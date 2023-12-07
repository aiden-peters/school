<?php
   $query = "SELECT * FROM orderTicket";
   $result = $connection->query($query);
   echo "What date are you looking up? </br>";
   while ($row = $result->fetch()) {
        echo '<input type="radio" name="orderRadio" value="';
        echo $row["orderID"];
        echo '">' . $row["date"] . "<br>";
   }
?>