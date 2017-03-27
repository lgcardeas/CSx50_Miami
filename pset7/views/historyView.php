<?php
    
    
    if ( ($result = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"])) == false) {
        echo("<I>An error has occurred... Probably you do not have any share yet..</I>");
    } else {
        echo '<table class = "table table-striped table-bordered">';
            echo '<thead >';
                echo "<tr>";
                    echo "<th width = 15%>Action</th>";
                    echo "<th width = 40%>Date/Time</th>";
                    echo "<th width = 15%>Symbol</th>";
                    echo "<th width = 15%>Shares</th>";
                    echo "<th width = 15%>Price</th>";
                echo "</tr>";
            echo "</thead>";
            echo "<tbody>";
                foreach ( $result as $row ){
                    echo "<tr>";  
                        echo "<td width = 15%> ".$row["method"]." </td>";
                        echo "<td width = 40%> ".$row["date"]." </td>";
                        echo "<td width = 15%> ".$row["symbol"]." </td>";
                        echo "<td width = 15%> $".$row["shares"]." </td>";
                        echo "<td width = 15%> $".$row["price"]." </td>";
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