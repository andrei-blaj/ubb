<?php
    session_start(); 
    
    $mysqli = new mysqli('localhost', 'root', '', 'NewsService');

    $category = $_POST['selected_category'];

    // echo($category);

    $sql = "SELECT * FROM News WHERE category = '$category' ORDER BY date DESC";
    $response = mysqli_query($mysqli, $sql);

    if (mysqli_num_rows($response) > 0) {

        while($row = mysqli_fetch_assoc($response)){
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

    } else {
        echo "There are no news in the selected category.";
    }
    

?>