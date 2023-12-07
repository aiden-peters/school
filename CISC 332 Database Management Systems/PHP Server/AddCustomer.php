<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Add Customer</title>
</head>
<body>
    
<?php
include 'rconnect.php';
?>
    <h2> ADD A NEW CUSTOMER:</h2>
<form action="addnew.php" method="post">
New Customer's First Name: <input type="text" name="firstname"><br>
New Customer's Last Name: <input type="text" name="lastname"><br>
New Customer's Email: <input type="text" name="email"><br>
New Customer's Postal Code: <input type="text" name="postalcode"><br>
New Customer's Address: <input type="text" name="address"><br>
New Customer's City: <input type="text" name="city"><br>
New Customer's Related: <input type="text" name="id"><br>
<?php

?>
<input type="submit" value="Add New Customer">
</form>
<?php
$connection = NULL;
?>
</body>
</html> 