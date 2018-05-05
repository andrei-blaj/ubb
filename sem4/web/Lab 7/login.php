<?php 
  session_start();

  if ($_SESSION['logged_in'] == 'true') {
    header("location: index.php");
  } else {
    $_SESSION['message'] = '';
    $_SESSION['logged_in'] = 'false';
  }

  $mysqli = new mysqli('localhost', 'root', '', 'NewsService');

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    $username = $_POST['username'];
    $password = md5($_POST['password']);

    $sql = "SELECT * FROM User WHERE username='" . $username . "' AND password='" . $password . "' LIMIT 1";

    $response = mysqli_query($mysqli, $sql);

    if (mysqli_num_rows($response) == 1) {

      while($row = mysqli_fetch_array($response)){
        $_SESSION['user_id'] = ''. $row['ID'] .'';
      }

      $_SESSION['message'] = 'Welcome, '. $username .'!';
      $_SESSION['logged_in'] = 'true';
      $_SESSION['selected_news_id'] = '';
      header("location: index.php");
    }

  }

?>  

<!DOCTYPE html>
<html>

<head>
  <title>News Service</title>
  <link rel="stylesheet" type="text/css" href="main.css">
</head>

<body>

  <div class="login-page">
    <div class="form">

      <form class="login-form" method="POST" action="login.php">

        <input type="text" placeholder="username" name="username" required/>
        <input type="password" placeholder="password" name="password" required/>

        <input class="submit" type="submit" name="login" value="Login">

        <p class="message">Not registered? <a href="register.php">Create an account</a></p>

      </form>

    </div>
  </div>

</body>

</html>