<?php
$servername = "172.20.241.9";
$username = "dbaccess_ro";
$password = "vsdjkvwselkvwe234wv234vsdfas";
$dbname = "measurements";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
        }

$sql = "SELECT * FROM rawdata WHERE groupid = '62'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
   echo'<table border="1" cellpadding="5"><tr>';
   while($row = $result->fetch_assoc()) {
      echo "<td>" . $row["id"] . "</td><td>" . $row["timestamp"] . "</td><td>" .
         $row["groupid"] . "</td><td>" . $row["from_mac"] . "</td><td>" . $row["to_mac"] .
         "</td><td>" . $row["sensorvalue_a"] . "</td><td>" .
         $row["sensorvalue_b"] . "</td><td>" . $row["sensorvalue_c"] . "</td><td>" .
         $row["sensorvalue_d"] . "</td><td>" .
         $row["sensorvalue_e"] . "</td><td>" . $row["sensorvalue_f"] . "</tr>";
   }
        echo '</tr></table>';
}

$conn->close();
?>
