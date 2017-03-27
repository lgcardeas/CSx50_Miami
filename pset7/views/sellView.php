<form action = "sell.php" method = "post">
    <div class = "form-group">
        <select name="symbol" class = "form-group">
            <option disabled selected value>Symbol</option>
            <?php
            echo("loko");
                if (($shares = (CS50::query("SELECT * FROM portfolios WHERE user_id = ?",$_SESSION["id"]))) != false){
                    foreach($shares as $row){
                        ?>
                            <option value="<?= $row["symbol"]; ?>"><?= $row["symbol"]; ?></option>
                        <?php
                    }
                }
            ?>
        </select>
    </div>
    <div class = "form-group">
        <button class = "btn btn-default" type = "submit">SELL</button>
    </div>
</form>