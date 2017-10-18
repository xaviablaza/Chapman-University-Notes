using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinForms_ListBox
{
    class GameRecord : Record
    {
        public GameRecord(string title, int year, string genre, string developer)
        {
            this.Title = title;
            this.Year = year;
            this.Genre = genre;
            this.Developer = developer;
            this.RecordType = RecordType.Game;
        }
        public string Developer { get; set; }
    }
}
