using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinForms_ListBox
{
    class BookRecord : Record
    {
        public BookRecord(string title, int year, string genre, string author)
        {
            this.Title = title;
            this.Year = year;
            this.Genre = genre;
            this.Author = author;
            this.RecordType = RecordType.Book;
        }
        public string Author { get; set; }

    }
}
