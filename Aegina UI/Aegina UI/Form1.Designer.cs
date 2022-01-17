namespace Aegina_UI
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.panel1 = new System.Windows.Forms.Panel();
            this.lblFilePath = new System.Windows.Forms.Label();
            this.btnGetFile = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.txtTarget = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.cbErasePEB = new System.Windows.Forms.CheckBox();
            this.cbLoadLibrary = new System.Windows.Forms.CheckBox();
            this.chHandleHijack = new System.Windows.Forms.CheckBox();
            this.cbManualMap = new System.Windows.Forms.CheckBox();
            this.btnInject = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.DarkSlateGray;
            this.panel1.Controls.Add(this.lblFilePath);
            this.panel1.Controls.Add(this.btnGetFile);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.txtTarget);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.cbErasePEB);
            this.panel1.Controls.Add(this.cbLoadLibrary);
            this.panel1.Controls.Add(this.chHandleHijack);
            this.panel1.Controls.Add(this.cbManualMap);
            this.panel1.Controls.Add(this.btnInject);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(-4, -2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(411, 307);
            this.panel1.TabIndex = 0;
            // 
            // lblFilePath
            // 
            this.lblFilePath.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblFilePath.ForeColor = System.Drawing.Color.White;
            this.lblFilePath.Location = new System.Drawing.Point(22, 145);
            this.lblFilePath.Name = "lblFilePath";
            this.lblFilePath.Size = new System.Drawing.Size(371, 18);
            this.lblFilePath.TabIndex = 10;
            this.lblFilePath.Text = "Choose Dll File";
            this.lblFilePath.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnGetFile
            // 
            this.btnGetFile.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnGetFile.Font = new System.Drawing.Font("Segoe UI", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGetFile.ForeColor = System.Drawing.Color.White;
            this.btnGetFile.Location = new System.Drawing.Point(120, 110);
            this.btnGetFile.Name = "btnGetFile";
            this.btnGetFile.Size = new System.Drawing.Size(160, 29);
            this.btnGetFile.TabIndex = 9;
            this.btnGetFile.Text = "Select File";
            this.btnGetFile.UseVisualStyleBackColor = true;
            this.btnGetFile.Click += new System.EventHandler(this.btnGetFile_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(154, 55);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(98, 18);
            this.label3.TabIndex = 8;
            this.label3.Text = "Target Name:";
            // 
            // txtTarget
            // 
            this.txtTarget.Font = new System.Drawing.Font("Segoe UI Emoji", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTarget.Location = new System.Drawing.Point(88, 77);
            this.txtTarget.Name = "txtTarget";
            this.txtTarget.Size = new System.Drawing.Size(230, 27);
            this.txtTarget.TabIndex = 7;
            this.txtTarget.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtTarget.ForeColor = System.Drawing.Color.White;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.SystemColors.AppWorkspace;
            this.label2.Location = new System.Drawing.Point(163, 224);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(76, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Coming Soon..";
            // 
            // cbErasePEB
            // 
            this.cbErasePEB.AutoSize = true;
            this.cbErasePEB.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.cbErasePEB.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbErasePEB.ForeColor = System.Drawing.Color.White;
            this.cbErasePEB.Location = new System.Drawing.Point(226, 266);
            this.cbErasePEB.Name = "cbErasePEB";
            this.cbErasePEB.Size = new System.Drawing.Size(86, 20);
            this.cbErasePEB.TabIndex = 5;
            this.cbErasePEB.Text = "Erase peb";
            this.cbErasePEB.UseVisualStyleBackColor = true;
            // 
            // cbLoadLibrary
            // 
            this.cbLoadLibrary.AutoSize = true;
            this.cbLoadLibrary.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.cbLoadLibrary.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbLoadLibrary.ForeColor = System.Drawing.Color.White;
            this.cbLoadLibrary.Location = new System.Drawing.Point(85, 266);
            this.cbLoadLibrary.Name = "cbLoadLibrary";
            this.cbLoadLibrary.Size = new System.Drawing.Size(95, 20);
            this.cbLoadLibrary.TabIndex = 4;
            this.cbLoadLibrary.Text = "LoadLibrary";
            this.cbLoadLibrary.UseVisualStyleBackColor = true;
            // 
            // chHandleHijack
            // 
            this.chHandleHijack.AutoSize = true;
            this.chHandleHijack.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.chHandleHijack.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chHandleHijack.ForeColor = System.Drawing.Color.White;
            this.chHandleHijack.Location = new System.Drawing.Point(225, 240);
            this.chHandleHijack.Name = "chHandleHijack";
            this.chHandleHijack.Size = new System.Drawing.Size(108, 20);
            this.chHandleHijack.TabIndex = 3;
            this.chHandleHijack.Text = "Handle Hijack";
            this.chHandleHijack.UseVisualStyleBackColor = true;
            // 
            // cbManualMap
            // 
            this.cbManualMap.AutoSize = true;
            this.cbManualMap.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.cbManualMap.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbManualMap.ForeColor = System.Drawing.Color.White;
            this.cbManualMap.Location = new System.Drawing.Point(85, 240);
            this.cbManualMap.Name = "cbManualMap";
            this.cbManualMap.Size = new System.Drawing.Size(97, 20);
            this.cbManualMap.TabIndex = 2;
            this.cbManualMap.Text = "Manual Map";
            this.cbManualMap.UseVisualStyleBackColor = true;
            // 
            // btnInject
            // 
            this.btnInject.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnInject.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnInject.ForeColor = System.Drawing.Color.White;
            this.btnInject.Location = new System.Drawing.Point(75, 167);
            this.btnInject.Name = "btnInject";
            this.btnInject.Size = new System.Drawing.Size(259, 54);
            this.btnInject.TabIndex = 1;
            this.btnInject.Text = "Inject";
            this.btnInject.UseVisualStyleBackColor = true;
            this.btnInject.Click += new System.EventHandler(this.btnInject_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(84, 8);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(245, 37);
            this.label1.TabIndex = 0;
            this.label1.Text = "Aegina Injector";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(402, 299);
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Aegina Inector";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnInject;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtTarget;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox cbErasePEB;
        private System.Windows.Forms.CheckBox cbLoadLibrary;
        private System.Windows.Forms.CheckBox chHandleHijack;
        private System.Windows.Forms.CheckBox cbManualMap;
        private System.Windows.Forms.Button btnGetFile;
        private System.Windows.Forms.Label lblFilePath;
    }
}

