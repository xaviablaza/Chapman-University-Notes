using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms_ListBox
{
    public partial class ViewForm : Form
    {
        Form1 form1ref; // This is a reference to Form1
        public ViewForm(Form1 form1ref, Record record)
        {
            this.form1ref = form1ref;
            this.Record = record;
            InitializeComponent();
            if (Record is BookRecord)
            {
                label1.Text = "Book Details";
                label2.Text = "Author";
                BookRecord book = Record as BookRecord;
                label3.Text = book.Author;
            }
            else if (Record is MovieRecord)
            {
                label1.Text = "Movie Details";
                label2.Text = "Director";
                MovieRecord movie = Record as MovieRecord;
                label3.Text = movie.Director;
            }
            else if (Record is GameRecord)
            {
                label1.Text = "Game Details";
                label2.Text = "Developer";
                GameRecord game = Record as GameRecord;
                label3.Text = game.Developer;
            }
            label5.Text = Record.Genre;
            label7.Text = Record.Year.ToString();
            label9.Text = Record.Title;
        }

        public Record Record { get; set; }

        private void button1_Click(object sender, EventArgs e)
        {
            // Trigger the Close event for ViewForm
            this.Close();
        }
    }
}
