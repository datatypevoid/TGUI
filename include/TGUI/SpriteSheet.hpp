/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012-2014 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_SPRITE_SHEET_HPP
#define TGUI_SPRITE_SHEET_HPP


#include <TGUI/Picture.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Load one big image and split it into smaller images so that you can display tiles or play an animation.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API SpriteSheet : public Picture
    {
      public:

        typedef SharedWidgetPtr<SpriteSheet> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        SpriteSheet();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Virtual destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~SpriteSheet() {}


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual SpriteSheet* clone() override
        {
            return new SpriteSheet(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Set the position of the widget
        ///
        /// This function completely overwrites the previous position.
        /// See the move function to apply an offset based on the previous position instead.
        /// The default position of a transformable widget is (0, 0).
        ///
        /// \param position  New position
        ///
        /// \see move, getPosition
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setPosition(const sf::Vector2f& position) override;
        using Transformable::setPosition;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the picture cell, so the piece that is shown.
        ///
        /// \param size  The new size of the picture cell.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(const sf::Vector2f& size) override;
        using Transformable::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of a picture cell, so the piece that is shown.
        ///
        /// \return Size of the cell
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::Vector2f getSize() const override
        {
            return m_texture.getSize();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change the number of rows and columns in the image.
        ///
        /// \param rows     The amount of rows in the picture
        /// \param columns  The amount of columns in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setCells(unsigned int rows, unsigned int columns);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change the number of rows in the image.
        ///
        /// \param rows  The amount of rows in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setRows(unsigned int rows)
        {
            setCells(rows, m_columns);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the number of rows in the image.
        ///
        /// \return The amount of rows in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getRows() const
        {
            return m_rows;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change the number of columns in the image.
        ///
        /// \param columns  The amount of columns in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setColumns(unsigned int columns)
        {
            setCells(m_rows, columns);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the number of columns in the image.
        ///
        /// \return The amount of columns in the picture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getColumns() const
        {
            return m_columns;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Choose which cell should be displayed.
        ///
        /// \param row     The row in which the visible cell is located
        /// \param column  The column in which the visible cell is located
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setVisibleCell(unsigned int row, unsigned int column);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns which cell is being displayed.
        ///
        /// \return A vector containing the row and column in which the visible cell is located
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sf::Vector2u getVisibleCell() const
        {
            return m_visibleCell;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        // This function is a (slow) way to set properties on the widget, no matter what type it is.
        // When the requested property doesn't exist in the widget then the functions will return false.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setProperty(std::string property, const std::string& value) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        // This function is a (slow) way to get properties of the widget, no matter what type it is.
        // When the requested property doesn't exist in the widget then the functions will return false.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void getProperty(std::string property, std::string& value) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        // Returns a list of all properties that can be used in setProperty and getProperty.
        // The second value in the pair is the type of the property (e.g. int, uint, string, ...).
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::list< std::pair<std::string, std::string> > getPropertyList() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Defines specific triggers to SpriteSheet.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum SpriteSheetCallbacks
        {
            AllSpriteSheetCallbacks = PictureCallbacksCount - 1, ///< All triggers defined in SpriteSheet and its base classes
            SpriteSheetCallbacksCount = PictureCallbacksCount
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        unsigned int m_rows = 1;
        unsigned int m_columns = 1;

        sf::Vector2u m_visibleCell = sf::Vector2u{1, 1};
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_SPRITE_SHEET_HPP

