/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012-2013 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_MESSAGE_BOX_HPP
#define TGUI_MESSAGE_BOX_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API MessageBox : public ChildWindow
    {
      public:

        typedef SharedWidgetPtr<MessageBox> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        MessageBox();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        MessageBox(const MessageBox& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~MessageBox();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        MessageBox& operator= (const MessageBox& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual MessageBox* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Loads the widget.
        ///
        /// \param configFileFilename  Filename of the config file.
        ///
        /// The config file must contain a MessageBox section with the needed information.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool load(const std::string& configFileFilename);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the filename of the config file that was used to load the widget.
        ///
        /// \return Filename of loaded config file.
        ///         Empty string when no config file was loaded yet.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const std::string& getLoadedConfigFile();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change the text of the message box.
        ///
        /// \param text  The text displayed by the message box.
        ///
        /// The text will be placed as one long string and the message box will get the size needed to display the whole string.
        /// So if you need to display multiple lines of text then add '\n' inside the text yourself.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setText(const sf::String& text);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Return the text of the message box.
        ///
        /// \return Text that is being displayed inside the message box.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sf::String getText();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the font of the text.
        ///
        /// When you don't call this function then the global font will be use.
        /// This global font can be changed with the setGlobalFont function from the parent.
        ///
        /// \param font  The new font.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextFont(const sf::Font& font);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the font of the text.
        ///
        /// \return  Pointer to the font that is currently being used.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const sf::Font* getTextFont() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the color of the text.
        ///
        /// \param color  New text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColor(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the color of the text.
        ///
        /// \return The current text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const sf::Color& getTextColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the character size of the text.
        ///
        /// \param size  The new text size.
        ///
        /// By default, the text size is 16.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextSize(unsigned int size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the character size of the text.
        ///
        /// \return The current text size.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getTextSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Add a button to the message box.
        ///
        /// \param buttonCaption  The caption of the button.
        ///
        /// When receiving a callback with the ButtonClicked trigge then callback.text will contain this caption to identify
        /// the clicked button.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addButton(const sf::String& buttonCaption);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // These functions are a (slow) way to set properties on the widget, no matter what type it is.
        // You can e.g. change the "Text" property, without even knowing that the widget is a button.
        // When the requested property doesn't exist in the widget then the functions will return false.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool setProperty(const std::string& property, const std::string& value);
        virtual bool getProperty(const std::string& property, std::string& value);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes sure all widgets lie within the window and places them on the correct position.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rearrange();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Callback functions for the buttons
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void ButtonClickedCallbackFunction(const Callback& callback);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        enum MessageBoxCallbacks
        {
            ButtonClicked            = ChildWindowCallbacksCount * 1,
            AllMessageBoxCallbacks   = ChildWindowCallbacksCount * 2 - 1,
            MessageBoxCallbacksCount = ChildWindowCallbacksCount * 2
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        std::string m_LoadedConfigFile;
        std::string m_ButtonConfigFileFilename;

        std::vector<Button::Ptr> m_Buttons;

        Label::Ptr m_Label;

        unsigned int m_TextSize;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_MESSAGE_BOX_HPP

