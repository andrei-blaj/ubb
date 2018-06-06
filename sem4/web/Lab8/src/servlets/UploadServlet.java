package servlets;

import models.User;
import repositories.UserRepository;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Part;
import java.io.*;
import java.sql.*;

@WebServlet(name = "UploadServlet", urlPatterns = {"/uploadImage"})
@MultipartConfig(fileSizeThreshold = 1024 * 1024 * 2, // 2MB
        maxFileSize = 1024 * 1024 * 10, // 10MB
        maxRequestSize = 1024 * 1024 * 50)

public class UploadServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String imagesFolderPath = "/Users/blaj/IdeaProjects/Lab8/web/images";

        response.setContentType("text/html;charset=UTF-8");

        PrintWriter out = response.getWriter();

        Part part = request.getPart("file");

        HttpSession session = request.getSession();

        String username = "" + session.getAttribute("username");
        String user_id = "" + session.getAttribute("id");

        String fileName = extractFileName(part);

        String savePath = imagesFolderPath + File.separator + fileName;

        File fileSaveDir = new File(savePath);

        part.write(savePath + File.separator);

        try {

            String JDBC_DRIVER = "com.mysql.jdbc.Driver";
            String DB_URL = "jdbc:mysql://localhost:3306/jspLab";

            String DbUser = "root";
            String DbPassword = "";

            Class.forName("com.mysql.jdbc.Driver");

            Connection conn = DriverManager.getConnection(DB_URL, DbUser, DbPassword);

            PreparedStatement pst = conn.prepareStatement("insert into images (url, user_id) values (?, ?)");
            pst.setString(1, fileName);
            pst.setString(2, user_id);
            pst.executeUpdate();

            RequestDispatcher rd = request.getRequestDispatcher("/index.jsp");

            rd.forward(request, response);

        } catch (Exception e) {
            out.println(e);
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    private String extractFileName(Part part) {
        String contentDisp = part.getHeader("content-disposition");
        String[] items = contentDisp.split(";");

        for (String s : items) {
            if (s.trim().startsWith("filename")) {
                return s.substring(s.indexOf("=") + 2, s.length() - 1);
            }
        }
        return "";
    }

}
