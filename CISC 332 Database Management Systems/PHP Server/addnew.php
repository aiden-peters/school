<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Customer - Database</title>
</head>
<body>
<?php
   include 'rconnect.php';
?>
<ol>
<?php
   $firstName= $_POST["firstname"];
   $lastName = $_POST["lastname"];
   $email =$_POST["email"];
   $postalCode= $_POST["postalcode"];
   $address = $_POST["address"];
   $city =$_POST["city"];
   $id =$_POST["id"];
   $query1 = 'INSERT INTO customer (firstname,lastname,email,PC,streetNumber,city,relationship) values("' . $firstName . '","' . $lastName . '",
   "' . $email . '","' . $postalCode . '","' . $address . '","' . $city . '", "'. $id .'")';
   $query2 = 'SELECT * FROM customer WHERE email="'.$email.'"';
   $result = $connection->query($query2);
   $count = $result->fetchAll();
   if($count!=[]){
    echo "Customer already in database.";
   } else {
      $numRows = $connection->exec($query1);
      echo "Your customer was added!";
      $query3 = 'INSERT INTO payment values("'.date("Y/m/d").'","5.00","'.$email.'")';
      $result = $connection->exec($query3);
   }

   $connection = NULL;
?>
</ol>
</body>
</html>