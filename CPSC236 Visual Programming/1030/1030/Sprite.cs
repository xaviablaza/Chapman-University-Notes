using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;

namespace _1030
{
    class Sprite
    {
        //Current position of Sprite 
        public Vector2 Position = new Vector2(0, 0);

        //The texture object used when drawing the sprite 
        private Texture2D mSpriteTexture;

        //The asset name for the Srite's Texture 
        public string AssetName;

        //The Size of the SPrite (with scale applied) 
        public Rectangle Size;

        //The sie of each indidual fram of the sprite 
        public int FrameSize;

        //The amount to increase/decrease the size of the original sprite. 
        private float mScale = 1.0f;

        //When the scale is modified throught he property, the size of the 
        //sprite is recalculated with new scale applied. 
        public float Scale
        {
            get { return mScale; }
            set
            {
                mScale = value;
                //Recalculate the Size of the Sprite with the new scale 
                Size = new Rectangle(0,0,(int)(mSpriteTexture.Width*Scale),(int)(mSpriteTexture.Height*Scale));

            }
        }
        
        //Load the texture for the sprite using the Content Pipline 
        public void LoadContent(ContentManager theContentManager, string theAssetName)
        {
            mSpriteTexture = theContentManager.Load<Texture2D>(theAssetName);
            AssetName = theAssetName;
            Size = new Rectangle(0, 0, (int)(mSpriteTexture.Width * Scale), (int)(mSpriteTexture.Height * Scale));

        }

        //Draw the SPrite to the screen 
        public void Draw(SpriteBatch theSpriteBatch)
        {
            theSpriteBatch.Draw(mSpriteTexture, Position, new Rectangle(0, 0, mSpriteTexture.Width, mSpriteTexture.Height),
                Color.White, 0.0f, Vector2.Zero, Scale, SpriteEffects.None, 0);

        }

        //Update the PSrite and change its position based on the passed in speed, driections and elapsed time. 
        public void Update(GameTime theGameTime, Vector2 theSpeed, Vector2 theDirection)
        {
            Position += theDirection * theSpeed * (float)theGameTime.ElapsedGameTime.TotalSeconds;
        }

    }
}
