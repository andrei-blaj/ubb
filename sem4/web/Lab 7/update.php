<?php 
  session_start();

  if ($_SESSION['logged_in'] == 'false') {
    $_SESSION['login'] = 'Log in';
    $_SESSION['message'] = '';
    header("location: index.php");
  }

  if ($_SESSION['selected_news_id'] == '') {
    header("location: index.php");
  }

  $mysqli = new mysqli('localhost', 'root', '', 'NewsService');

  $get_news = "SELECT * FROM News WHERE ID='" . $_SESSION['selected_news_id'] . "' LIMIT 1";

  $response = mysqli_query($mysqli, $get_news);

  while($row = mysqli_fetch_array($response)){
    $title = ''. $row['title'] .'';
    $description = ''. $row['Content'] .'';
    $producer = ''. $row['producer'] .'';
    $category = ''. $row['category'] .'';
  }

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    $title = $mysqli->real_escape_string($_POST['title']);
    $description = $mysqli->real_escape_string($_POST['description']);
    $producer = $mysqli->real_escape_string($_POST['producer']);
    $category = $mysqli->real_escape_string($_POST['category']);

    $id = $_SESSION['selected_news_id'];

    $sql = "UPDATE News SET Content = '$description', title = '$title', producer = '$producer', category = '$category' WHERE ID = '$id'";

    if ($mysqli->query($sql) === true) {
      $_SESSION['selected_news_id'] = '';
      header("location: index.php");
    } else {
      header("location: update.php");
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

      <form class="register-form" method="POST" action="update.php">

        <div style="margin-bottom: 15px;">
          <?= $title ?>
        </div>

        <input type="text" placeholder="title" name="title" value="<?= $title ?>" required/>
        <input type="text" placeholder="description" name="description" value="<?= $description ?>" required/>
        <input type="text" placeholder="producer" name="producer" value="<?= $producer ?>" required/>
        <input type="text" placeholder="category" name="category" value="<?= $category ?>" required/>

        <input class="submit" type="submit" name="create" value="Update News">

      </form>

    </div>
  </div>

</body>

</html>