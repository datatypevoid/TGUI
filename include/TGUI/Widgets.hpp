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


#ifndef TGUI_WIDGETS_HPP
#define TGUI_WIDGETS_HPP

#include <TGUI/Callback.hpp>
#include <TGUI/Transformable.hpp>
#include <TGUI/Container.hpp>
#include <TGUI/SharedWidgetPtr.hpp>
#include <TGUI/ConfigFile.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class Container;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief The parent class for every widget.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API Widget : public sf::Drawable, public Transformable, public CallbackManager
    {
      public:

        typedef SharedWidgetPtr<Widget> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget(const Widget& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~Widget();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget& operator= (const Widget& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget by just calling the copy constructor.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Widget* clone() = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Shows the widget.
        ///
        /// The widget won't receive events nor will it be drawn when hidden. The widget is visible by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void show();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Hides the widget.
        ///
        /// The widget won't receive events nor will it be drawn when hidden. The widget is visible by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void hide();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the widget is visible.
        ///
        /// \return Is the widget visible?
        ///
        /// If this function returns false then the widget is hidden, which means that it won't receive events and it won't be drawn.
        /// All widgets are visible by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isVisible() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Enables the widget.
        ///
        /// The widget will receive events and send callbacks again.
        /// All widgets are enabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void enable();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Disables the widget.
        ///
        /// The widget will no longer receive events and it will thus no longer send callbacks.
        /// All widgets are enabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void disable();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the widget is enabled.
        ///
        /// \return Is the widget enabled?
        ///
        /// If this function returns false then the widget is disabled and will longer receive events and it will thus no longer send callbacks.
        /// All widgets are enabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isEnabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the widget is disabled.
        ///
        /// \return Is the widget disabled?
        ///
        /// This means that the widget will longer receive events and it will thus no longer send callbacks.
        /// All widgets are enabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the widget is loaded successfully.
        ///
        /// \return Is the widget loaded?
        ///
        /// When an widget is not loaded correctly then it will not be drawn.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isLoaded() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Focus the widget.
        ///
        /// The previously focused widget will be unfocused.
        ///
        /// \see unfocus
        /// \see focusNextWidget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void focus();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Unfocus the widget.
        ///
        /// \see focus
        /// \see focusNextWidget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void unfocus();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Focus the next widget.
        ///
        /// Similar to unfocus, but another widget will gain the focus.
        ///
        /// \see focus
        /// \see unfocus
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void focusNextWidget();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the widget is focused and false otherwise.
        ///
        /// \return Is the widget focused?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isFocused() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the type of the widget.
        ///
        /// \return Type of the widget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        WidgetTypes getWidgetType() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns a pointer to the parent widget.
        ///
        /// \return Pointer to the parent.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Container* getParent() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the transparency of the widget.
        ///
        /// \param transparency  The transparency of the widget.
        ///                      0 is completely transparent, while 255 (default) means fully opaque.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTransparency(unsigned char transparency);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the transparency of the widget.
        ///
        /// \return The transparency of the widget.
        ///         0 is completely transparent, while 255 (default) means fully opaque.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned char getTransparency() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Places the widget before all other widgets.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void moveToFront();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Places the widget behind all other widgets.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void moveToBack();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the callback id of the widget.
        ///
        /// \param callbackId  The new callback id
        ///
        /// When receiving callback in a function which takes a Callback as parameter (or when polling the callbacks),
        /// you can find a callbackId in this Callback struct which can identify the widget.
        /// This function changes the id that this widget sends on a callback.
        ///
        /// By default, the callback id will be 0.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setCallbackId(unsigned int callbackId);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the callback id of the widget.
        ///
        /// \return Callback id
        ///
        /// \see setCallbackId
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getCallbackId();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called right after the elapsed time is changed.
        // The elapsed time is only changed when the widget has set m_AnimatedWidget to true.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void update();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // The widgets use this function to send their callbacks to their parent and/or to a callback function.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addCallback();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the mouse enters the widget. If requested, a callback will be send.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseEnteredWidget();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the mouse leaves the widget. If requested, a callback will be send.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void mouseLeftWidget();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Get the WidgetPhases from the string read from the info file.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void extractPhases(std::string phases);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Used to communicate with EventManager.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnWidget(float x, float y) = 0;
        virtual void leftMousePressed(float x, float y);
        virtual void leftMouseReleased(float x, float y);
        virtual void mouseMoved(float x, float y);
        virtual void keyPressed(sf::Keyboard::Key key);
        virtual void textEntered(sf::Uint32 key);
        virtual void mouseWheelMoved(int delta, int x, int y);
        virtual void widgetFocused();
        virtual void widgetUnfocused();
        virtual void mouseNotOnWidget();
        virtual void mouseNoLongerDown();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // These functions are a (slow) way to set properties on the widget, no matter what type it is.
        // You can e.g. change the "Text" property, without even knowing that the widget is a button.
        // When the requested property doesn't exist in the widget then the functions will return false.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool setProperty(const std::string& property, const std::string& value);
        virtual bool getProperty(const std::string& property, std::string& value);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the widget is added to a container.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void initialize(tgui::Container *const container);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        enum WidgetCallbacks
        {
            None = 0,
            Focused = 1,
            Unfocused = 2,
            MouseEntered = 4,
            MouseLeft = 8,
            WidgetCallbacksCount = 16
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        // When an widget is disabled, it will no longer receive events
        bool m_Enabled;

        // Is the widget visible? When it is invisible it will not receive events and it won't be drawn.
        bool m_Visible;

        // This bool will be true from the moment that the load function is completed successfully.
        bool m_Loaded;

        // This will store the different phases that the widget can have
        // e.g. if there isn't a mouse down image then a button should not try to change its image on mouse down
        unsigned char m_WidgetPhase;

        // This will point to our parent widget. If there is no parent then this will be NULL.
        Container* m_Parent;

        // How transparent is the widget
        unsigned char m_Opacity;

        // Is the mouse on top of the widget? Did the mouse go down on the widget?
        bool m_MouseHover;
        bool m_MouseDown;

        // Are you focused on the widget?
        bool m_Focused;

        // Can the widget be focused?
        bool m_AllowFocus;

        // Keep track of the elapsed time.
        bool m_AnimatedWidget;
        sf::Time m_AnimationTimeElapsed;

        // This is set to true for widgets that have something to be dragged around (e.g. sliders and scrollbars)
        bool m_DraggableWidget;

        // This is set to true for widgets that store other widgets inside them
        bool m_ContainerWidget;

        // Instead of creating a new widget every time, one callback widget is always reused
        Callback m_Callback;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        friend class EventManager;
        friend class Container;
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Parent class for every widget that has borders.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API WidgetBorders
    {
      public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        WidgetBorders();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the borders.
        ///
        /// \param leftBorder    Size of the left border
        /// \param topBorder     Size of the top border
        /// \param rightBorder   Size of the right border
        /// \param bottomBorder  Size of the bottom border
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBorders(unsigned int leftBorder = 0,  unsigned int topBorder = 0,
                                unsigned int rightBorder = 0, unsigned int bottomBorder = 0) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the borders as a tgui::Vector4u.
        ///
        /// \return border sizes
        ///
        /// The first element will be the size of the left border, the seconds is the size of the top border,
        /// the third is the size of the right border and the the last constains the size of the bottom border.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector4u getBorders() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        unsigned int m_LeftBorder;
        unsigned int m_TopBorder;
        unsigned int m_RightBorder;
        unsigned int m_BottomBorder;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_WIDGETS_HPP
