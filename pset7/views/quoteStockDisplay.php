<?php
    if (isset($_POST["symbol"])){
        $stock = lookup($_POST["symbol"]);
        if ($stock != null){
            echo "A share of " . $stock["name"] . '(' . $stock["symbol"] . ')' . " costs <B><I>$"  . $stock["price"] . "</I></B>.<br>";
        } else {
            $symbol =  $_POST["symbol"] == "" ? "Non-name" : $_POST["symbol"];
            echo ("<B><I>Please, provide a valid information... No share found with this symbol (" . $symbol . ")</I></B>");
        }
    } else {
        apologize("An error has occurred!!!!! ");
    }
?>