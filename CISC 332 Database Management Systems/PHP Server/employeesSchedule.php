<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Employees</title>
</head>
<body>
    
<?php
include 'rconnect.php';
?>
    <h2>Our Employees</h2>
    <form action="getemployee.php" method="post">
<?php
   include 'getedata.php';
?>
<input type="submit" value="Get Employee">
</form>
<?php
$connection = NULL;
?>
</body>
</html> 