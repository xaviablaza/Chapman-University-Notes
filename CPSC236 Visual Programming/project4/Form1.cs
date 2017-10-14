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
    public partial class Form1 : Form
    {
        ViewForm addForm;
        BindingList<BookRecord> bookList;
        List<GameRecord> gameList;
        List<MovieRecord> movieList;

        public Form1()
        {
            addForm = new ViewForm(this);
            bookList = new BindingList<BookRecord>();
            gameList = new List<GameRecord>();
            movieList = new List<MovieRecord>();
            InitializeComponent();
            listboxName.DataSource = bookList;
            listboxName.DisplayMember = "Title";
        }

        private void btnEnterName_Click(object sender, EventArgs e)
        {
            /*string name = "Xavi";

            // Check to make sure the user has actually entered text into the textbox
            if (name.Trim() != "")
            {
                // ListBoxes have a container called "Items", to which you can add objects, such as strings
                listboxName.Items.Add(name);
            }*/

            //this.addForm.ShowDialog();
            
            bookList.Add(new BookRecord("Bob", 2011, "Fantasy", "John"));





        }

      //  private void textEnterName_KeyUp(object sender, KeyEventArgs e)
       // {
        //    if (e.KeyCode == Keys.Return)
         //       btnEnterName_Click(sender, e);
        //}

        private void btnDeleteName_Click(object sender, EventArgs e)
        {
            // The selected item in your ListBox is referenced by the SelectedIndex. It's a 0-based index.
            // If no item is selected, the index is -1, which doesn't exist, so make sure to not try to delete it
            if (listboxName.SelectedIndex > -1)
            {
                // Remove from the the ListBox Items at the particular index that was selected
                listboxName.Items.RemoveAt(listboxName.SelectedIndex);
            }
        }


        private void textEnterName_TextChanged(object sender, EventArgs e)
        {

        }

        private void listboxName_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
