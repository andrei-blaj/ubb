<?php 
  session_start();

  $mysqli = new mysqli('localhost', 'root', '', 'NewsService');

  $_SESSION['selected_news_id'] = '';

  if ($_SESSION['logged_in'] == 'false') {
    $_SESSION['login'] = 'Log in';
    $_SESSION['user_id'] = '';
  } else {
    $_SESSION['login'] = 'Log out';
  }

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    if (isset($_POST['logout'])) {

      if ($_SESSION['logged_in'] == 'true') {
        $_SESSION['logged_in'] = 'false';
        $_SESSION['message'] = '';
        
        header("location: index.php");
      } else {
        header("location: login.php");
      }
    }

    if (isset($_POST['new'])) {
      header("location: new.php");
    }
    
    if (isset($_POST['edit'])) {
      $_SESSION['selected_news_id'] = $_POST['edit'];
      header("location: update.php");
    }

  }

?>

<!DOCTYPE html>
<html>

<head>
  <title>News Service</title>
  <link rel="stylesheet" type="text/css" href="main.css">
  <script src="https://code.jquery.com/jquery-3.3.1.js"></script>

  <script>
    $(document).ready(function() {
      $('.filter-by-category').click(function() {
        var filter_by_category = $('#category-filter').find(':selected').text();
        // alert(filter_by_category);
        $('#news').load("filter.php", {
          selected_category: filter_by_category
        });
      });
    });
  </script>

</head>

<body>


  <div style="float: left;">
    <?= $_SESSION['message'] ?>
  </div>

  <div style="float: right;">
    <form class="form" style=" height: 46px; padding: 1px;" method="POST" action="index.php">
      <input class="submit" type="submit" name="logout" value="<?= $_SESSION['login']?>">
    </form>
  </div>

  <?php 
    if ($_SESSION['logged_in'] == 'true') {
      echo '<div style="float: right;">';
      echo '<form class="form" style=" height: 46px; padding: 1px;" method="POST" action="index.php">';
      echo '<input class="submit" type="submit" name="new" value="Add News">';
      echo '</form>';
      echo '</div>';
    }
  ?>

  <center>
    <div id="main">

      <h1> News </h1>
      <div style="float: left;">

        <select id="category-filter">
          <option>politics</option>
          <option>society</option>
          <option>health</option>
          <option>Star Wars</option>
          <option>gta</option>
          <option>australia</option>
        </select>

        <button class="filter-by-category"> Filter </button>

      </div> 

      <!-- <div style="float: right;">

        <select id="category-filter">
          <option>politics</option>
          <option>society</option>
          <option>health</option>
          <option>Star Wars</option>
          <option>gta</option>
          <option>australia</option>
        </select>

        <button class="filter-by-category"> Filter </button>

      </div>  -->

      <br />
      <br />

      <div id="news">

        <?php
          
          $sql = "SELECT * FROM News";
          $response = mysqli_query($mysqli, $sql);

          while($row = mysqli_fetch_array($response)){
            $id = ''. $row['ID'] .'';
            $title = ''. $row['title'] .'';
            $description = ''. $row['Content'] .'';
            $producer = ''. $row['producer'] .'';
            $category = ''. $row['category'] .'';
            $date = ''. $row['date'] .'';
            $user_id = ''. $row['user_id'] .'';

            echo '<div style="margin-bottom: 75px; border-top: 1px solid #ddd;">';
            echo '<b><h2 style="margin-left: 20px; margin-right: 20px;">'. $title .'</h2></b>';
            echo '<h4 style="margin-left: 20px; text-align: left; text-indent: 50px;">'. $description .'</h4>';
            echo '<h5 style="margin-left: 20px; text-align: left;">'. $producer .', '. $category .', '. $date .'</h5>';
            if ($_SESSION['user_id'] == $user_id) {
              echo '<form method="POST" action="index.php">';
              echo '<button style="margin-bottom: 50px;" class="edit" type="submit" name="edit" value="'.$id.'"> Edit </button>';
              echo '</form>';
            }
            echo '</div>';
          }

        ?>

      </div>

    </div>
  </center>
</body>

</html>