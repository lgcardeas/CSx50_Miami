<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buyView.php", ["title" => "BuyView"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (isset($_POST["symbol"]) && isset($_POST["shares"])){
            if (($share = CS50::query("SELECT * FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"])) !== false){
                $stock = lookup($_POST["symbol"]);
                $moneyToAdd = $stock["price"] * $_POST["shares"];
                //VALIDATIONS
                if (($user = CS50::query("SELECT cash FROM users WHERE id =? ", $_SESSION["id"])) !== false){
                    if ($user[0]["cash"] < $moneyToAdd){
                        apologize("You don't have enough money to buy!!!!");
                    }
                }else{
                    apologize("An error has occurred!!!!");
                }
                
                
                if (!is_numeric($_POST["shares"]) || !is_int($_POST["shares"])){
                    apologize("You must enter a valid number of shares to buy...");
                }
            
                if ($stock == null){
                    apologize("No share name found.....");
                }
            
                if (count($share) == 0){ //Insert into the table
                    if (($share = CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?,?,?)",
                                                                            $_SESSION["id"],
                                                                            $_POST["symbol"],
                                                                            $_POST["shares"])) === false){
                        apologize("An error has occurred... Impossible to buy");        
                        
                    }
                    
                } else { //Just update the value
                     if (($resultUpdate = CS50::query("UPDATE portfolios SET shares = shares + ? WHERE symbol = ?", $_POST["shares"], $_POST["symbol"])) === false){
                         apologize("An error has occurred...");        
                     } 
                }
                //UPDATE users values
                if (($resultUpdate = CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $moneyToAdd, $_SESSION["id"])) !== false){
                    ($history = CS50::query("INSERT INTO history (method, date, symbol, shares, price, user_id) VALUES(\"BUY\",?,?,?,?,?)",
                                                                            date("Y-m-d h:m:sa"),
                                                                            $_POST["symbol"],
                                                                            $_POST["shares"],
                                                                            $stock["price"],
                                                                            $_SESSION["id"]));
                   redirect("/");
                } else {
                    apologize("An error has occurred.. We couldn't return your money!!!!");            
                }
            } else {
                apologize("An error has occurred...");
            }
        } else {
            apologize("Please, you must to select a valid Symbol to sell...");
        }
    } else {
            apologize("An error has occurred.. Please provide valid information");
    }
    

?>