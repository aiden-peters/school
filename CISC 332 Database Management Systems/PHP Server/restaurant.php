<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Restaurant</title>
</head>
<body>
    <h1>Welcome to the Restaurant</h1>
    <img src='https://cdn.vox-cdn.com/thumbor/L8NF6YQlRhNE9f6M4GwVyRtAAek=/0x0:2564x2564/920x613/filters:focal(1059x809:1469x1219):format(webp)/cdn.vox-cdn.com/uploads/chorus_image/image/71377462/01_Cauliflower___Front.0.jpg' alt='photo of restaurant' />
<?php
include 'rconnect.php';
?>
    <li><a href="OrdersByDate.php"> Orders By Date</a>
    <li><a href="AddCustomer.php"> Add Customer</a>
    <li><a href="OrderCountTable.php"> Number of Orders</a>
    <li><a href="EmployeesSchedule.php"> Employees Schedule</a>
<?php
$connection = NULL;
?>
</body>
</html> 