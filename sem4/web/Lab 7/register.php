<?php 
  session_start();

  if ($_SESSION['logged_in'] == 'true') {
    $_SESSION['login'] = 'Log out';
    header("location: index.php");
  } else {
    $_SESSION['message'] = '';
    $_SESSION['logged_in'] = 'false';
  }

  $mysqli = new mysqli('localhost', 'root', '', 'NewsService');

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if ($_POST['password'] == $_POST['confirm_password']) {
      $username = $mysqli->real_escape_string($_POST['username']);
      $email = $mysqli->real_escape_string($_POST['email']);
      $password = md5($_POST['password']);

      $_SESSION['username'] = $username;

      $sql = "INSERT INTO User (username, password, email) " . "VALUES ('$username', '$password', '$email') ";

      if ($mysqli->query($sql) === true) {
        
        $get_user = "SELECT * FROM User WHERE username='" . $username . "' AND password='" . $password . "' LIMIT 1";

        $response = mysqli_query($mysqli, $get_user);

        while($row = mysqli_fetch_array($response)){
          $_SESSION['user_id'] = ''. $row['ID'] .'';
        }

        $_SESSION['message'] = 'Welcome, '. $username .'!';
        $_SESSION['logged_in'] = 'true';
        $_SESSION['selected_news_id'] = '';
        header("location: index.php");
      } else {
        $_SESSION['message'] = 'User could not be saved to the database!';
      }

    } else {
      $_SESSION['message'] = 'Passwords do not match!';
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

      <form class="register-form" method="POST" action="register.php">

        <div style="margin-bottom: 15px;">
          <?= $_SESSION['message'] ?>
        </div>

        <input type="text" placeholder="username" name="username" required/>
        <input type="text" placeholder="email" name="email" required/>
        <input type="password" placeholder="password" name="password" required/>
        <input type="password" placeholder="confirm password" name="confirm_password" required/>
        
        <input class="submit" type="submit" name="register" value="Register">

        <p class="message">Already registered? <a href="login.php">Sign In</a></p>

      </form>

    </div>
  </div>

</body>

</html>