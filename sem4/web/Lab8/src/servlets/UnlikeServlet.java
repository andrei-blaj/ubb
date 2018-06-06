package servlets;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.*;

@WebServlet(name = "UnlikeServlet", urlPatterns = {"/unlike"})
public class UnlikeServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String image_id = "" + request.getParameter("id");

        HttpSession session = request.getSession();
        String user_id = "" + session.getAttribute("id");

        String JDBC_DRIVER = "com.mysql.jdbc.Driver";
        String DB_URL = "jdbc:mysql://localhost:3306/jspLab";

        String DbUser = "root";
        String DbPassword = "";

        try {

            Class.forName(JDBC_DRIVER);

            Connection conn = DriverManager.getConnection(DB_URL, DbUser, DbPassword);

            Statement didUserLikeStmt = conn.createStatement();
            String didUserLikeSql = "SELECT * FROM likes WHERE user_id=" + user_id + " AND img_id=" + image_id + "";
            ResultSet didUserLikeRs = didUserLikeStmt.executeQuery(didUserLikeSql);

            Integer didUserLike = 0;
            while (didUserLikeRs.next()) {
                didUserLike = didUserLike + 1;
            }

            if (didUserLike != 0) {

                PreparedStatement pst = conn.prepareStatement("DELETE FROM likes WHERE user_id=" + user_id + " AND img_id=" + image_id + "");
                pst.executeUpdate();

            }

        } catch (Exception e) {
            System.out.println(e);
        }

        RequestDispatcher rd = request.getRequestDispatcher("/index.jsp");

        rd.forward(request, response);
    }
}
