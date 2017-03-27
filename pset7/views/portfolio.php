<?php
    
    
    if ( ($result = CS50::query("SELECT id, user_id, symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"])) == 0) {
        apologize("An error has occurred... Probably you do not have any share yet..");
    } else {
        echo '<table class = "table table-striped table-bordered">';
            echo '<thead >';
                echo "<tr>";
                    echo "<th width = 15%>Symbol</th>";
                    echo "<th width = 40%>Name</th>";
                    echo "<th width = 15%>Shares</th>";
                    echo "<th width = 15%>Price</th>";
                    echo "<th width = 15%>TOTAL</th>";
                echo "</tr>";
            echo "</thead>";
            echo "<tbody>";
                foreach ( $result as $row ){
                    $stock = lookup($row["symbol"]);
                    echo "<tr>";  
                        echo "<td width = 15%> ".$stock["symbol"]." </td>";
                        echo "<td width = 40%> ".$stock["name"]." </td>";
                        echo "<td width = 15%> ".$row["shares"]." </td>";
                        echo "<td width = 15%> $".$stock["price"]." </td>";
                        echo "<td width = 15%> $".$stock["price"] * $row["shares"]." </td>";
                    echo "</tr>";   
                }
                if ( ($result = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])) != 0) {
                    echo "<tr>";  
                        echo "<td width = 15%>CASH</td>";
                        echo "<td width = 40%></td>";
                        echo "<td width = 15%></td>";
                        echo "<td width = 15%></td>";
                        echo "<td width = 15%> $".$result[0]["cash"]." </td>";
                    echo "</tr>"; 
                }
            echo "</tbody>";
        echo "</table>";
    }
    
?>