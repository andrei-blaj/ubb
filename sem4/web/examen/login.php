<?php 
  session_start();

  if ($_SESSION['logged_in'] == 'true') {
    header("location: index.php");
  } else {
    $_SESSION['message'] = '';
    $_SESSION['logged_in'] = 'false';
  }

  $mysqli = new mysqli('localhost', 'root', '', 'examen');

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    $username = $_POST['username'];
    $password = md5($_POST['password']);

    $sql = "SELECT * FROM Person WHERE user='" . $username . "' AND secretNumber='" . $password . "' LIMIT 1";

    $response = mysqli_query($mysqli, $sql);

    if (mysqli_num_rows($response) == 1) {

      while($row = mysqli_fetch_array($response)){
        $_SESSION['user_id'] = ''. $row['id'] .'';
        $_SESSION['name'] = ''. $row['name'] .'';
        $_SESSION['url'] = ''.$row['pictureFile'] .'';
        $_SESSION['family_members'] = ''.$row['familyMembers'] .'';
      }

      $_SESSION['message'] = 'Welcome, '. $username .'!';
      $_SESSION['logged_in'] = 'true';
      header("location: index.php");
    }

  }

?>  

<!DOCTYPE html>
<html>

<head>
  <title> Examen </title>
  <link rel="stylesheet" type="text/css" href="main.css">
</head>

<body>

  <div class="login-page">
    <div class="form">

      <form class="login-form" method="POST" action="login.php">

        <input type="text" placeholder="username" name="username" required/>
        <input type="password" placeholder="secret number" name="password" required/>

        <input class="submit" type="submit" name="login" value="Login">

      </form>

    </div>
  </div>

</body>

</html>