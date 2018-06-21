<?php
    session_start(); 
    
    $mysqli = new mysqli('localhost', 'root', '', 'examen');

    $user_id = $_POST['user_id'];

    // echo($category);

    $sql = "SELECT * FROM Friend WHERE userId = '$user_id'";
    $response = mysqli_query($mysqli, $sql);

    if (mysqli_num_rows($response) > 0) {
        echo '<table>';
        while($row = mysqli_fetch_assoc($response)){
            $id = ''. $row['friendId'] .'';
            
            $sql = "SELECT * FROM Person WHERE id='" . $id . "'";
            $result = mysqli_query($mysqli, $sql);
            
            echo '<tr>';
            if (mysqli_num_rows($result) > 0) {
              while($row = mysqli_fetch_assoc($result)){
                $id = ''. $row['id'] .'';
                $name = ''. $row['name'] .'';
                $url = ''. $row['pictureFile'] .'';

                echo '<td>' . $name . '</td>';
                echo '<td><img src="'. $url .'" height="100px"></td>';
                echo '<td><form class="login-form" method="POST" action="index.php">';
                echo '<input type="hidden" name="enemyId" value="'.$id.'">';
                echo '<input class="submit" type="submit" name="enemy" value="Enemy">';
                echo '</form></td>';
              }
              echo '</tr>';
            }
        }
        echo '</table>';

    } else {
        echo "User has no friends.";
    }
    

?>