<?php
   $query = "SELECT * FROM Employee";
   $result = $connection->query($query);
   echo "Which Employee are you looking up? </br>";
   while ($row = $result->fetch()) {
        echo '<input type="radio" name="employeeRadio" value="';
        echo $row["EmployeeID"];
        echo '">' . $row["firstName"] . " " . $row["lastName"] . " Employee ID: ". $row["EmployeeID"] . "<br>";
   }
?>