using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms_ListBox
{
    public partial class Form1 : Form
    {
        BindingList<Record> bookList;
        BindingList<Record> gameList;
        BindingList<Record> movieList;
        const string FILENAME = "records.txt";

        public Form1()
        {
            bookList = new BindingList<Record>();
            gameList = new BindingList<Record>();
            movieList = new BindingList<Record>();
            loadFile(bookList, movieList, gameList, FILENAME);
            InitializeComponent();
            listboxBook.DataSource = bookList;
            listboxBook.DisplayMember = "Title";
            listBoxMovie.DataSource = movieList;
            listBoxMovie.DisplayMember = "Title";
            listboxGame.DataSource = gameList;
            listboxGame.DisplayMember = "Title";
        }

        private void btnEnterName_Click(object sender, EventArgs e)
        {
            string title = bookTitle.Text.ToString();
            int year;
            string yearStr = bookYear.Text.ToString();
            string genre = bookGenre.Text.ToString();
            string author = bookAuthor.Text.ToString();
            if (title == "" || yearStr == "" || genre == "" || author == "")
            {
                yearLabel.Text = "";
                label13.Text = "All fields must be filled out before adding record.";
            }
            else if (int.TryParse(yearStr, out year) && year>=0)
            {
                label13.Text = "";
                bookList.Add(new BookRecord(bookTitle.Text.ToString().Trim(), year, bookGenre.Text.ToString().Trim(), bookAuthor.Text.ToString().Trim()));
                yearLabel.Text = "";
                bookTitle.Text = "";
                bookYear.Text = "";
                bookGenre.Text = "";
                bookAuthor.Text = "";
            }
            else
            {
                label13.Text = "";
                yearLabel.Text = "Year could not be parsed properly.";
            }
        }

        private void btnDeleteName_Click(object sender, EventArgs e)
        {
            // The selected item in your ListBox is referenced by the SelectedIndex. It's a 0-based index.
            // If no item is selected, the index is -1, which doesn't exist, so make sure to not try to delete it
            if (listboxBook.SelectedIndex > -1)
            {
                // Remove from the the ListBox Items at the particular index that was selected
                listboxBook.Items.RemoveAt(listboxBook.SelectedIndex);
            }
        }

        private void listboxName_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            string title = movieTitle.Text.ToString();
            int year;
            string yearStr = movieYear.Text.ToString();
            string genre = movieGenre.Text.ToString();
            string director = movieDirector.Text.ToString();
            if (title == "" || yearStr == "" || genre == "" || director == "")
            {
                label14.Text = "";
                label15.Text = "All fields must be filled out before adding record.";
            }
            else if (int.TryParse(yearStr, out year) && year >= 0)
            {
                label15.Text = "";
                movieList.Add(new MovieRecord(movieTitle.Text.ToString().Trim(), year, movieGenre.Text.ToString().Trim(), movieDirector.Text.ToString().Trim()));
                label14.Text = "";
                movieTitle.Text = "";
                movieYear.Text = "";
                movieGenre.Text = "";
                movieDirector.Text = "";
            }
            else
            {
                label15.Text = "";
                label14.Text = "Year could not be parsed properly.";
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // The selected item in your ListBox is referenced by the SelectedIndex. It's a 0-based index.
            // If no item is selected, the index is -1, which doesn't exist, so make sure to not try to delete it
            if (listBoxMovie.SelectedIndex > -1)
            {
                // Remove from the the ListBox Items at the particular index that was selected
                listBoxMovie.Items.RemoveAt(listBoxMovie.SelectedIndex);
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            string title = gameTitle.Text.ToString();
            int year;
            string yearStr = gameYear.Text.ToString();
            string genre = gameGenre.Text.ToString();
            string developer = gameDeveloper.Text.ToString();
            if (title == "" || yearStr == "" || genre == "" || developer == "")
            {
                label16.Text = "";
                label17.Text = "All fields must be filled out before adding record.";
            }
            else if (int.TryParse(yearStr, out year) && year >= 0)
            {
                label17.Text = "";
                gameList.Add(new GameRecord(gameTitle.Text.ToString().Trim(), year, gameGenre.Text.ToString().Trim(), gameDeveloper.Text.ToString().Trim()));
                label16.Text = "";
                gameTitle.Text = "";
                gameYear.Text = "";
                gameGenre.Text = "";
                gameDeveloper.Text = "";
            }
            else
            {
                label17.Text = "";
                label16.Text = "Year could not be parsed properly.";
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            // The selected item in your ListBox is referenced by the SelectedIndex. It's a 0-based index.
            // If no item is selected, the index is -1, which doesn't exist, so make sure to not try to delete it
            if (listboxGame.SelectedIndex > -1)
            {
                // Remove from the the ListBox Items at the particular index that was selected
                listboxGame.Items.RemoveAt(listboxGame.SelectedIndex);
            }
        }

        private void btnViewBook_Click(object sender, EventArgs e)
        {
            if (listboxBook.SelectedIndex > -1)
            {
                // Remove from the the ListBox Items at the particular index that was selected
                Record record = (Record)listboxBook.Items[listboxBook.SelectedIndex];
                ViewForm viewForm = new ViewForm(this, record);
                viewForm.ShowDialog();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (listBoxMovie.SelectedIndex > -1)
            {
                // Remove from the the ListBox Items at the particular index that was selected
                Record record = (Record)listBoxMovie.Items[listBoxMovie.SelectedIndex];
                ViewForm viewForm = new ViewForm(this, record);
                viewForm.ShowDialog();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (listboxGame.SelectedIndex > -1)
            {
                // Remove from the the ListBox Items at the particular index that was selected
                Record record = (Record)listboxGame.Items[listboxGame.SelectedIndex];
                ViewForm viewForm = new ViewForm(this, record);
                viewForm.ShowDialog();
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            using (StreamWriter sw = new StreamWriter(FILENAME, false))
            {
                foreach (BookRecord br in bookList)
                {
                    sw.WriteLine("Book," + br.Title + "," + br.Year + "," + br.Genre + "," + br.Author);
                }
                foreach (MovieRecord mr in movieList)
                {
                    sw.WriteLine("Movie," + mr.Title + "," + mr.Year + "," + mr.Genre + "," + mr.Director);
                }
                foreach (GameRecord gr in gameList)
                {
                    sw.WriteLine("Game," + gr.Title + "," + gr.Year + "," + gr.Genre + "," + gr.Developer);
                }
            }
        }

        private bool loadFile(BindingList<Record> books, BindingList<Record> movies, BindingList<Record> games, string fileName)
        {
            // If file exists, then attempt to load it into dictionary
            if (File.Exists(fileName))
            {
                try
                {   // Open the text file using a stream reader.
                    using (StreamReader sr = new StreamReader(fileName))
                    {
                        // Read the stream to a string, and write the string to the console.
                        String line = sr.ReadToEnd();
                        String[] vals = line.Split(',');
                        if (vals[0] == "Book")
                        {
                            bookList.Add(new BookRecord(vals[1], int.Parse(vals[2]), vals[3], vals[4]));
                        }
                        else if (vals[0] == "Movie")
                        {
                            movieList.Add(new MovieRecord(vals[1], int.Parse(vals[2]), vals[3], vals[4]));
                        }
                        else if (vals[0] == "Game")
                        {
                            gameList.Add(new GameRecord(vals[1], int.Parse(vals[2]), vals[3], vals[4]));
                        }
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("The file could not be read:");
                    Console.WriteLine(e.Message);
                    return false;
                }
                Console.WriteLine("Successfully loaded " + fileName);
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
