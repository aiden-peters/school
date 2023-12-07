<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Restaurant-Your Orders</title>
</head>
<body>
<?php
include 'rconnect.php';
?>
<h1>Here are your orders:</h1>
<table border="3" style="width: 100%">
<?php
   $query = 'SELECT COUNT(orderID), date FROM orderTicket GROUP BY date ORDER BY date';
   $result=$connection->query($query);
   echo "<tr><th>Date</th><th>Number of Orders</th></tr>";
    while ($row=$result->fetch()) {
	echo "<tr><td>".$row["date"]."</td><td>".$row["COUNT(orderID)"]."</td></tr>";
    }
?>
</table>
<?php
   $connection = NULL;
?>
</body>
</html>