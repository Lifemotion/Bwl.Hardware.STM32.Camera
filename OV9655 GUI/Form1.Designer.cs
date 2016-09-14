namespace OV9655_GUI
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.Button bRS485;
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.ports_list = new System.Windows.Forms.ComboBox();
            this.speed_list = new System.Windows.Forms.ComboBox();
            this.bOpen = new System.Windows.Forms.Button();
            this.bPhoto = new System.Windows.Forms.Button();
            bRS485 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 54);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(396, 336);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // ports_list
            // 
            this.ports_list.FormattingEnabled = true;
            this.ports_list.Location = new System.Drawing.Point(12, 12);
            this.ports_list.Name = "ports_list";
            this.ports_list.Size = new System.Drawing.Size(99, 21);
            this.ports_list.TabIndex = 1;
            // 
            // speed_list
            // 
            this.speed_list.FormattingEnabled = true;
            this.speed_list.Location = new System.Drawing.Point(132, 12);
            this.speed_list.Name = "speed_list";
            this.speed_list.Size = new System.Drawing.Size(90, 21);
            this.speed_list.TabIndex = 2;
            // 
            // bOpen
            // 
            this.bOpen.Location = new System.Drawing.Point(244, 12);
            this.bOpen.Name = "bOpen";
            this.bOpen.Size = new System.Drawing.Size(164, 21);
            this.bOpen.TabIndex = 3;
            this.bOpen.Text = "Открыть порт";
            this.bOpen.UseVisualStyleBackColor = true;
            // 
            // bPhoto
            // 
            this.bPhoto.Location = new System.Drawing.Point(12, 396);
            this.bPhoto.Name = "bPhoto";
            this.bPhoto.Size = new System.Drawing.Size(268, 23);
            this.bPhoto.TabIndex = 4;
            this.bPhoto.Text = "Сделать снимок";
            this.bPhoto.UseVisualStyleBackColor = true;
            // 
            // bRS485
            // 
            bRS485.Location = new System.Drawing.Point(288, 396);
            bRS485.Name = "bRS485";
            bRS485.Size = new System.Drawing.Size(120, 23);
            bRS485.TabIndex = 5;
            bRS485.Text = "Отправить по RS485";
            bRS485.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(420, 433);
            this.Controls.Add(bRS485);
            this.Controls.Add(this.bPhoto);
            this.Controls.Add(this.bOpen);
            this.Controls.Add(this.speed_list);
            this.Controls.Add(this.ports_list);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "OV9655 GUI";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ComboBox ports_list;
        private System.Windows.Forms.ComboBox speed_list;
        private System.Windows.Forms.Button bOpen;
        private System.Windows.Forms.Button bPhoto;
    }
}

