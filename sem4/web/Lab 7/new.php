<?php 
  session_start();

  if ($_SESSION['logged_in'] == 'false') {
    $_SESSION['login'] = 'Log in';
    $_SESSION['message'] = '';
    header("location: index.php");
  }

  $mysqli = new mysqli('localhost', 'root', '', 'NewsService');

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    $title = $mysqli->real_escape_string($_POST['title']);
    $description = $mysqli->real_escape_string($_POST['description']);
    $producer = $mysqli->real_escape_string($_POST['producer']);
    $category = $mysqli->real_escape_string($_POST['category']);
    $date = date('Y/m/d H:i:s');
    $user_id = $_SESSION['user_id'];

    $sql = "INSERT INTO News (Content, title, producer, date, category, user_id) " . "VALUES ('$description', '$title', '$producer', '$date', '$category', '$user_id') ";

    if ($mysqli->query($sql) === true) {
      header("location: index.php");
    } else {
      $_SESSION['message'] = 'News could not be saved to the database!';
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

      <form class="register-form" method="POST" action="new.php">

        <div style="margin-bottom: 15px;">
          <?= $_SESSION['message'] ?>
        </div>

        <input type="text" placeholder="title" name="title" required/>
        <input type="text" placeholder="description" name="description" required/>
        <input type="text" placeholder="producer" name="producer" required/>
        <input type="text" placeholder="category" name="category" required/>

        <input class="submit" type="submit" name="create" value="Create News">

      </form>

    </div>
  </div>

</body>

</html>