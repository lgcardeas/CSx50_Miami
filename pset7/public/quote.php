<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET") {
        // else render form
        render("quoteStockForm.php", ["title" => "SutmitFormStock"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST") {
            render("quoteStockDisplay.php", ["title" => "StockDisplay"]);
        } else {
            apologize("An error has occurred....");
        }

?>