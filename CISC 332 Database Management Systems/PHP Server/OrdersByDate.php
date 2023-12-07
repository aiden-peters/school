<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Orders By Date</title>
</head>
<body>
    
<?php
include 'rconnect.php';
?>
    <h2>Our orders</h2>
    <form action="getorders.php" method="post">
<?php
   include 'getrdata.php';
?>
<input type="submit" value="Get Orders">
</form>
<?php
$connection = NULL;
?>
</body>
</html> 