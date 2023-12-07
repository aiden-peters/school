<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Restaurant-Your Schedule</title>
</head>
<body>
<?php
include 'rconnect.php';
?>
<h1>Schedule:</h1>
<table border="3" style="width: 100%">
<?php
   $schedule= $_POST["employeeRadio"];
   $query = 'SELECT * FROM shift
   WHERE EmployeeID="' . $schedule . '"';
   $result=$connection->query($query);
   echo "<tr><th>Date</th><th>Start Time</th><th>End Time</th></tr>";
    while ($row=$result->fetch()) {
	echo "<tr><td>".$row["date"]."</td><td>".$row["startTime"].
    "</td><td>".$row["endTime"]."</td></tr>";
    }
?>
</table>
<?php
   $connection = NULL;
?>
</body>
</html>