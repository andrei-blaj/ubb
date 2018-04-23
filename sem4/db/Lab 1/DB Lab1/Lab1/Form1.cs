using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Lab1
{
    public partial class Form1 : Form
    {
        SqlDataAdapter daParinte;
        SqlDataAdapter daChild;
        DataSet dset;
        DataRelation relation;
        BindingSource bsParinte;
        BindingSource bsCopil;
        SqlCommandBuilder cmdbuilder;

        public Form1()
        {
            InitializeComponent();
            FillData();
        }

        void FillData()
        {
            SqlConnection conn = new SqlConnection(getConnString());
            daParinte = new SqlDataAdapter("select * from Service", conn);
            daChild = new SqlDataAdapter("select * from Client", conn);
            cmdbuilder = new SqlCommandBuilder(daChild);
            dset = new DataSet();


            daParinte.Fill(dset, "Service");
            daChild.Fill(dset, "Client");

            DataRelation drel = new DataRelation("fk_clients_service",
                dset.Tables["Service"].Columns["id_service"],
                dset.Tables["Client"].Columns["id_service"]);

            dset.Relations.Add(drel);

            bsParinte = new BindingSource();
            bsParinte.DataSource = dset;
            bsParinte.DataMember = "Service";

            bsCopil = new BindingSource();
            bsCopil.DataSource = bsParinte;
            bsCopil.DataMember = "fk_clients_service";

            this.dataGridViewParent.DataSource = bsParinte;
            this.dataGridChild.DataSource = bsCopil;
            


            /*
            SqlCommand cmd = new SqlCommand("select * from Client",conn);
            SqlDataReader rdr = null;

            try
            {
                conn.Open();
                rdr = cmd.ExecuteReader();
                while (rdr.Read())
                    Console.WriteLine(rdr[0] + " " + rdr[1]);
            }
            finally
            {
                if (rdr != null)
                    rdr.Close();
                if (conn != null)
                    conn.Close();
            } */

            /*
            SqlCommand cmd = new SqlCommand("insert Players(name) values(@param)", conn);

            SqlParameter param = new SqlParameter();
            param.ParameterName = "@param";
            param.SqlDbType = SqlDbType.NVarChar;
            param.Size = 50;
            param.Value = "Simona Halep";

            cmd.Parameters.Add(param);
            cmd.ExecuteNonQuery();
            */


        }

        private string getConnString()
        {
            return "Data Source =DESKTOP-DV60SSU\\SQLEXPRESS;" +
                "Initial Catalog = ServiceAuto;" +
                "Integrated Security = true";
        }

        private void updateButton_Click_1(object sender, EventArgs e)
        {
            daChild.Update(dset, "Client");
        }
    }
}
