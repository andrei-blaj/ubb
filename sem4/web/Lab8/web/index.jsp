<%@ page import="java.sql.*" %><%--
  Created by IntelliJ IDEA.
  User: blaj
  Date: 20/05/2018
  Time: 14:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>

    <%
        if (session.getAttribute("username") == null) {
            out.println("<title> Login </title>");
        } else {
            out.println("<title> Welcome, " + session.getAttribute("username") + "! </title>");
        }
    %>

    <style>
        .login-input-field {
            width: 300px;
            padding: 12px 20px;
            margin: 8px 0;
            border: 1px solid #ccc;
            box-sizing: border-box;
            position: absolute;
        }
        .margin-top-50 {
            margin-top: 50px;
        }
        .margin-top-100 {
            margin-top: 92px;
        }
    </style>
</head>
<body>

    <%

        if (session.getAttribute("username") == null) {
            out.println(
                "<div class=\"login-form\">\n" +
                "\n" +
                "\n" +
                "    <form action=\"/login\" method=\"POST\">\n" +
                "\n" +
                "        <input type=\"text\" placeholder=\"username\" name=\"username\" class=\"login-input-field\">\n" +
                "        <input type=\"password\" placeholder=\"password\" name=\"password\" class=\"login-input-field margin-top-50\">\n" +
                "\n" +
                "        <button type=\"submit\" class=\"login-input-field margin-top-100\"> Login </button>\n" +
                "\n" +
                "    </form>\n" +
                "</div>"
            );

        } else {

            out.println("Welcome, " + session.getAttribute("username") + ", user_id: " + session.getAttribute("id"));

            out.println(
                    "<form method=\"post\" action=\"/uploadImage\" enctype=\"multipart/form-data\">\n" +
                    "Select image:\n" +
                    "<input type=\"file\" name=\"file\" id=\"fileChooser\"/><br/><br/>\n" +
                    "<input type=\"submit\" value=\"Upload\" />\n" +
                    "</form>"
            );

            String JDBC_DRIVER = "com.mysql.jdbc.Driver";
            String DB_URL = "jdbc:mysql://localhost:3306/jspLab";

            String DbUser = "root";
            String DbPassword = "";

            try {
                Class.forName("com.mysql.jdbc.Driver");

                Connection conn = DriverManager.getConnection(DB_URL, DbUser, DbPassword);

                Statement st = conn.createStatement();
                String sql = "SELECT * FROM images";
                ResultSet rs = st.executeQuery(sql);

                out.println("<center><div style='width: 800px;'>");

                while (rs.next()) {

                    Integer image_id = rs.getInt("id");
                    String image_url = rs.getString("url");
                    String image_user_id = rs.getString("user_id");

                    Statement stmt = conn.createStatement();
                    String likesSql = "SELECT * FROM likes WHERE img_id=" + image_id + "";
                    ResultSet likesRS = stmt.executeQuery(likesSql);

                    Integer likeCount = 0;
                    while (likesRS.next()) {
                        likeCount = likeCount + 1;
                    }

                    Statement stmt1 = conn.createStatement();
                    String userSql = "SELECT * FROM user WHERE id=" + image_user_id + "";
                    ResultSet userRS = stmt1.executeQuery(userSql);

                    out.println("<a href='display.jsp?id=" + image_id + "'><img src='images/" + image_url + "' width='800px'></a>");
                    out.println("<h5 style='float: left; margin-right: 10px;'> Likes: " + likeCount + "</h5>");

                    while (userRS.next()) {
                        String image_username = userRS.getString("username");

                        out.println("<h5 style='float: left; margin-right: 10px;'> Added by: <a href='/user.jsp?id=" +  image_user_id + "'>" + image_username + "</a></h5>");
                    }

                    String user_id = "" + session.getAttribute("id");
                    Statement didUserLikeStmt = conn.createStatement();
                    String didUserLikeSql = "SELECT * FROM likes WHERE user_id=" + user_id + " AND img_id=" + image_id + "";
                    ResultSet didUserLikeRs = didUserLikeStmt.executeQuery(didUserLikeSql);

                    Integer didUserLike = 0;
                    while (didUserLikeRs.next()) {
                        didUserLike = didUserLike + 1;
                    }

                    if (didUserLike > 0) {
                        out.println("<h5 style='float: right;'><a href='/unlike?id=" + image_id + "'> Unlike </h5>");
                    } else {
                        out.println("<h5 style='float: right;'><a href='/like?id=" + image_id + "'> Like </h5>");
                    }

               }

                out.println("</div></center>");

            } catch (Exception e) {
                out.println(e);
            }
        }
    %>

</body>
</html>