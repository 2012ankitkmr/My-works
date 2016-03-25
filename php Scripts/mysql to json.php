<?php

// info that is in the form of string passes arguements so as to access the database on server
$host = "mysql_web_host.com";
$user = "ankit";
$password = "123456789";
$db_name = "datasheet"; //name of the database


$sql = "select * from login_data;";

$con_link = mysqli_connect($host,$user,$password,$db);
 
$result = mysqli_query($con_link,$sql);

$result_as_array = array();

while($row = mysqli_fetch_array($result))
{

  array_push($result_as_array,array("name"=>$row[0],"email"=>$row[1],"username"=>$row[2],"password"=>$row[3]));

}
$json_data=array("login_data"=>$result_as_array);


echo json_encode($json_data);
mysqli_close($con);
?>