<?php
    session_start(); 
    
    $mysqli = new mysqli('localhost', 'root', '', 'examen');

    $user_id = $_POST['user_id'];

    $array = [];
    $visited = [];

    $sql = "SELECT * FROM Friend WHERE userId = '$user_id'";
    $response = mysqli_query($mysqli, $sql);

    if (mysqli_num_rows($response) > 0) {
        
        while($row = mysqli_fetch_assoc($response)){
            $id = ''. $row['friendId'] .'';
            
            array_push($array, $id);
            array_push($visited, $id);
        }
    } else {
        echo "User has no friends.";
    }

    $array2 = [];

    for ($i = 0; $i < count($array); $i++) {

        $uid = $array[$i];
        $sql = "SELECT * FROM Friend WHERE userId = '$uid'";
        $response = mysqli_query($mysqli, $sql);

        if (mysqli_num_rows($response) > 0) {
            while($row = mysqli_fetch_assoc($response)){
                $id = ''. $row['friendId'] .'';
                
                if ($id != $user_id) {

                    $sql = "SELECT * FROM Person WHERE id='" . $id . "'";
                    $result = mysqli_query($mysqli, $sql);
                    
                    if (mysqli_num_rows($result) > 0) {
                        while($row = mysqli_fetch_assoc($result)){
                            $id = ''. $row['id'] .'';
                            $name = ''. $row['name'] .'';
                            $url = ''. $row['pictureFile'] .'';

                            if (!in_array($id, $visited)) {

                                array_push($array2, $id);

                            }
                        }
                    }
                }
            }

        }

    }

    echo '<table>';
    for ($i = 0; $i < count($array2); $i++) {

        $uid = $array2[$i];
        $sql = "SELECT * FROM Friend WHERE userId = '$uid'";
        $response = mysqli_query($mysqli, $sql);

        if (mysqli_num_rows($response) > 0) {
            while($row = mysqli_fetch_assoc($response)){
                $id = ''. $row['friendId'] .'';
                
                if ($id != $user_id) {

                    $sql = "SELECT * FROM Person WHERE id='" . $id . "'";
                    $result = mysqli_query($mysqli, $sql);
                    
                    if (mysqli_num_rows($result) > 0) {
                        while($row = mysqli_fetch_assoc($result)){
                            $id = ''. $row['id'] .'';
                            $name = ''. $row['name'] .'';
                            $url = ''. $row['pictureFile'] .'';

                            if (!in_array($id, $visited)) {
                                echo '<tr>';
                                echo '<td>' . $name . '</td>';
                                echo '<td><img src="'. $url .'" height="100px"></td>';
                                echo '<td><form class="login-form" method="POST" action="index.php">';
                                echo '<input type="hidden" name="enemyId" value="'.$id.'">';
                                echo '<input class="submit" type="submit" name="enemy" value="Enemy">';
                                echo '</form></td>';
                                echo '</tr>';

                                array_push($visited, $id);
                            }
                        }
                    }
                }
            }

        }

    }
    echo '</table>';

?>