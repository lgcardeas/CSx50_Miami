<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sellView.php", ["title" => "SellView"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {//Sell the product and redirect to portafolio.php;
        if (isset($_POST["symbol"])){
            if (($share = CS50::query("SELECT * FROM portfolios WHERE symbol = ? AND user_id = ?", $_POST["symbol"], $_SESSION["id"])) != false){
                
                $stock = lookup($share[0]["symbol"]);
                
                $moneyToAdd = $stock["price"] * $share[0]["shares"];
                
                if (($result = CS50::query("DELETE FROM portfolios WHERE symbol = ? AND user_id = ?", $_POST["symbol"], $_SESSION["id"])) != false){
                    if (($resultUpdate = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $moneyToAdd, $_SESSION["id"])) != false){
                        ($history = CS50::query("INSERT INTO history (method, date, symbol, shares, price, user_id) VALUES(\"SELL\",?,?,?,?,?)",
                                                                            date("Y-m-d h:m:sa\n"),
                                                                            $_POST["symbol"],
                                                                            $share[0]["shares"],
                                                                            $stock["price"],
                                                                            $_SESSION["id"]));
                        redirect("/");
                    } else {
                        apologize("An error has occurred.. We couldn't return your money!!!!");            
                    }
                } else {
                    apologize("An error has occurred.. We couldn't sell the share!!!!");        
                }
                
            } else {
                apologize("An error has occurred..");    
            }
        } else {
            apologize("You must to select a product to sell!!!");
        }
    } else {
            apologize("An error has occurred.. Please provide valid information");
    }
    

?>