using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OV9655_GUI
{
    public partial class Form1 : Form
    {
        SerialPort _port = null;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            String[] ports = SerialPort.GetPortNames();
            foreach (String port in ports)
            {
                ports_list.Items.Add(port);
            }
            ports_list.Refresh();

            speed_list.Items.Add("9600");
            speed_list.Items.Add("14400");
            speed_list.Items.Add("19200");
            speed_list.Items.Add("56000");
            speed_list.Items.Add("57600");
            speed_list.Items.Add("115200");
            speed_list.Items.Add("128000");
            speed_list.Items.Add("256000");
            speed_list.Refresh();
        }
    }
}
