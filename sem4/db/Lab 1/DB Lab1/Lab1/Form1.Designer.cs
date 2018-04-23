namespace Lab1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridViewParent = new System.Windows.Forms.DataGridView();
            this.dataGridChild = new System.Windows.Forms.DataGridView();
            this.updateButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewParent)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridChild)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewParent
            // 
            this.dataGridViewParent.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewParent.Location = new System.Drawing.Point(59, 61);
            this.dataGridViewParent.Name = "dataGridViewParent";
            this.dataGridViewParent.RowTemplate.Height = 28;
            this.dataGridViewParent.Size = new System.Drawing.Size(546, 217);
            this.dataGridViewParent.TabIndex = 0;
            // 
            // dataGridChild
            // 
            this.dataGridChild.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridChild.Location = new System.Drawing.Point(59, 325);
            this.dataGridChild.Name = "dataGridChild";
            this.dataGridChild.RowTemplate.Height = 28;
            this.dataGridChild.Size = new System.Drawing.Size(546, 200);
            this.dataGridChild.TabIndex = 1;
            // 
            // updateButton
            // 
            this.updateButton.BackColor = System.Drawing.SystemColors.Window;
            this.updateButton.Location = new System.Drawing.Point(628, 566);
            this.updateButton.Name = "updateButton";
            this.updateButton.Size = new System.Drawing.Size(144, 54);
            this.updateButton.TabIndex = 2;
            this.updateButton.Text = "UPDATE";
            this.updateButton.UseVisualStyleBackColor = false;
            this.updateButton.Click += new System.EventHandler(this.updateButton_Click_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(814, 658);
            this.Controls.Add(this.updateButton);
            this.Controls.Add(this.dataGridChild);
            this.Controls.Add(this.dataGridViewParent);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewParent)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridChild)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewParent;
        private System.Windows.Forms.DataGridView dataGridChild;
        private System.Windows.Forms.Button updateButton;
    }
}

