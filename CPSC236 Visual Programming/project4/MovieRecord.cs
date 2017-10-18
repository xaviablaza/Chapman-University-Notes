using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinForms_ListBox
{
    class MovieRecord : Record
    {
        public MovieRecord(string title, int year, string genre, string director)
        {
            this.Title = title;
            this.Year = year;
            this.Genre = genre;
            this.Director = director;
            this.RecordType = RecordType.Movie;
        }
        public string Director { get; set; }
    }
}
