<?php 
  session_start();

  $mysqli = new mysqli('localhost', 'root', '', 'examen');


  if ($_SESSION['logged_in'] == 'false') {
    $_SESSION['login'] = 'Log in';
    $_SESSION['user_id'] = '';
    header("location: login.php");
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

    if (isset($_POST['enemy'])) {
      $familyM = [];
      $enemyId = $_POST['enemyId'];

      $family = $_SESSION['family_members'];
      $aux = '';

      for ($i = 0; $i < strlen($family); $i++) {
        if ($family[$i] != ' ') {
          $aux = $aux . $family[$i];
        } else {
          array_push($familyM, $aux);
          $aux = '';
        }
      }

      if ($aux != '') {
        array_push($familyM, $aux);
      }
      
      for ($i = 0; $i < count($familyM); $i++) {
        $sql1 = "DELETE FROM Friend WHERE userId='" . $familyM[$i] . "' AND friendId='" . $enemyId . "'";
        $sql2 = "DELETE FROM Friend WHERE userId='" . $enemyId . "' AND friendId='" . $familyM[$i] . "'";

        $sql3 = mysqli_query($mysqli, $sql1);
        $sql4 = mysqli_query($mysqli, $sql2);
      }

      header("location: index.php");
      

    }

  }

?>

<!DOCTYPE html>
<html>

<head>
  <title>Profile</title>
  <link rel="stylesheet" type="text/css" href="main.css">
  <script src="https://code.jquery.com/jquery-3.3.1.js"></script>

  <script>
    $(document).ready(function() {

      var user_id = $('.user_id').text();
      
      $('.first-level-friends').load("first.php", {
        user_id: user_id
      });

      $('.second-level-friends').load("second.php", {
        user_id: user_id
      });

      $('.third-level-friends').load("third.php", {
        user_id: user_id
      });

    });

  </script>

</head>

<body>

  <div class="user_id" style='display: none;'>
    <?echo $_SESSION['user_id']?>
  </div>

  <div style="float: left;">
    <?= $_SESSION['message'] ?>
  </div>

  <div style="float: right;">
    <form class="form" style=" height: 46px; padding: 1px;" method="POST" action="index.php">
      <input class="submit" type="submit" name="logout" value="<?= $_SESSION['login']?>">
    </form>
  </div>

  <center>
    <div id="main">

      <div style="float: left;">
        <h1> <? echo($_SESSION['name']) ?> </h1>
        <? echo '<img src="'. $_SESSION['url'] .'" height="100px">'; ?>

        <h2> Family Members </h2>

        <?php 
          
          $familyM = [];

          $family = $_SESSION['family_members'];
          $aux = '';

          for ($i = 0; $i < strlen($family); $i++) {
            if ($family[$i] != ' ') {
              $aux = $aux . $family[$i];
            } else {
              array_push($familyM, $aux);
              $aux = '';
            }
          }

          if ($aux != '') {
            array_push($familyM, $aux);
          }

          echo '<table>';
          for ($i = 0; $i < count($familyM); $i++) {
            $sql = "SELECT * FROM Person WHERE id='" . $familyM[$i] . "'";
            $result = mysqli_query($mysqli, $sql);
            
            echo '<tr>';
            if (mysqli_num_rows($result) > 0) {
              while($row = mysqli_fetch_assoc($result)){
                $id = ''. $row['id'] .'';
                $name = ''. $row['name'] .'';
                $url = ''. $row['pictureFile'] .'';

                echo '<td>' . $name . '</td>';
                echo '<td><img src="'. $url .'" height="100px"></td>';
              }
              echo '</tr>';
            }

          }
          echo '</table>';

          if (count($familyM) == 0) {
            echo 'No family members.';
          }

        ?>

        <hr>

        First Level Friends
        <div class='first-level-friends'>
        </div>

        <hr>

        Second Level Friends

        <div class='second-level-friends'>
        </div>

        <hr>

        Third Level Friends

        <div class='third-level-friends'>
        </div>

      </div> 

    </div>
  </center>
</body>

</html>