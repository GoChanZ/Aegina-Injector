using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Aegina_UI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        enum AeginaStatus
        {
            STATUS_SUCCESSFUL_INJECTION,
            FILE_LOAD_ERROR,
            ID_FAILURE,
            ID_SUCCESS,
            HIJACK_HANDLE_SUCCESS,
            HIJACK_HANDLE_FAILURE,
            MEMORY_ALLOCATION_FAILURE,
            THREAD_FAILURE,
            WRITE_MEMORY_FAILURE,
            MEMORY_PROTECTION_FAILURE,
            INVALID_PROCESS,
            NTAPI_FAILURE,
            MANUAL_MAP_SUCCESS
        };

        private static bool isProcessRunning(string Name)
        {
            Process[] processes = Process.GetProcessesByName(Name);
            return processes.Length == 0 ? false : true;
        }
        [DllImport("Aegina.dll")]
        private static extern AeginaStatus Inject(string DllPath, string Target);
        private void btnInject_Click(object sender, EventArgs e)
        {
            AeginaStatus status = Inject(lblFilePath.Text, txtTarget.Text);
            if (status != AeginaStatus.STATUS_SUCCESSFUL_INJECTION)
            {
                System.Media.SystemSounds.Asterisk.Play();
                MessageBox.Show("Aegina error code: " + status);
            }
            else
            {
                System.Media.SystemSounds.Asterisk.Play();
                MessageBox.Show("Successful Injection!");
            }
        }

        private void btnGetFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "Dll Files (*.dll)|*.dll|All files (*.*)|*.*";
            dialog.InitialDirectory = "C:\\";
            dialog.Title = "Select a text file";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                lblFilePath.Text= dialog.FileName;
            }
        }

        private void txtTarget_TextChanged(object sender, EventArgs e)
        {
            if (isProcessRunning(txtTarget.Text))
            {
                txtTarget.Text = txtTarget.Text + ".exe";
                txtTarget.BackColor = Color.Green;
            }
            else
            {
                txtTarget.BackColor = Color.Red;
            }
        }

    }
}
