<%@ page import="java.sql.*" %><%--
  Created by IntelliJ IDEA.
  User: blaj
  Date: 02/06/2018
  Time: 20:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <%

        if (session.getAttribute("username") == null) {
            response.sendRedirect("/index.jsp");
        } else {

            String page_user_id = "" + request.getParameter("id");

            String user_id = "" + session.getAttribute("id");

            String JDBC_DRIVER = "com.mysql.jdbc.Driver";
            String DB_URL = "jdbc:mysql://localhost:3306/jspLab";

            String DbUser = "root";
            String DbPassword = "";

            Class.forName(JDBC_DRIVER);

            Connection conn = DriverManager.getConnection(DB_URL, DbUser, DbPassword);

            Statement stmt = conn.createStatement();
            String sql = "SELECT * FROM user WHERE id=" + page_user_id + "";
            ResultSet rs = stmt.executeQuery(sql);

            while (rs.next()) {
                String page_username = rs.getString("username");

                if (page_username != null) {

                    out.println("<title> " + page_username + " </title>");

                } else {

                    response.sendRedirect("index.jsp");

                }

            }

        }
    %>
</head>
<body>

    <a href="index.jsp">Home</a>

    <%

    try {

        Class.forName("com.mysql.jdbc.Driver");

        String DB_URL = "jdbc:mysql://localhost:3306/jspLab";

        String DbUser = "root";
        String DbPassword = "";

        Connection conn = DriverManager.getConnection(DB_URL, DbUser, DbPassword);

        String page_user_id = "" + request.getParameter("id");

        Statement st = conn.createStatement();
        String sql = "SELECT * FROM images WHERE user_id=" + page_user_id + "";
        ResultSet rs = st.executeQuery(sql);

        out.println("<center><div style='width: 800px;'>");

        while (rs.next()) {

            Integer image_id = rs.getInt("id");
            String image_url = rs.getString("url");
            //                String user_id = rs.getString("user_id");

            Statement stmt = conn.createStatement();
            String likesSql = "SELECT * FROM likes WHERE img_id=" + image_id + "";
            ResultSet likesRS = stmt.executeQuery(likesSql);

            Integer likeCount = 0;
            while (likesRS.next()) {
                likeCount = likeCount + 1;
            }

            out.println("<a href='display.jsp?id=" + image_id + "'><img src='images/" + image_url + "' width='800px'></a>");
            out.println("<h5 style='float: left; margin-right: 10px;'> Likes: " + likeCount + "</h5>");
//            out.println("<h5 style='float: left; margin-right: 10px;'> Added by: <a href='/user.jsp?id=" +  request.getParameter("id") + "'>" + session.getAttribute("username") + "</a></h5>");

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

    %>

</body>
</html>
