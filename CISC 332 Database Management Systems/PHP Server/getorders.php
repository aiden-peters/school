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
   $whichOrder= $_POST["orderRadio"];
   $query = 'SELECT * FROM orderTicket, customer, deliveryemployee
   WHERE delivered=EmployeeID AND orderticket.email=customer.email AND orderid="' . $whichOrder . '"';
   $result=$connection->query($query);
    
    while ($row=$result->fetch()) {
	echo "<tr><th>Customer First Name</th><th>Customer Last Name</th>
    <th>Items Ordered</th><th>Total Price</th>
    <th>Tip</th><th>Delivery First Name</th>
    <th>Delivery Last Name</th></tr><tr><td>".$row["firstName"]."</td><td>".$row["lastName"].
    "</td><td>".$row["orderedFood"].
    "</td><td>".$row["totalPrice"]."</td><td>".$row["tip"]."</td>
    <td>".$row["deliveryfirstName"]."</td><td>".$row["deliverylastName"]."</td></tr>";
    }
?>
</table>
<?php
   $connection = NULL;
?>
</body>
</html>