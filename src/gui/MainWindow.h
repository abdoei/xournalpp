/*
 * Xournal++
 *
 * The Main window
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include "GladeGui.h"
#include "../model/Font.h"
#include <XournalType.h>

class Control;
class MainWindow;
class ToolMenuHandler;
class ToolbarData;
class ToolbarModel;
class XournalView;

class MainWindow: public GladeGui {
public:
	MainWindow(GladeSearchpath * gladeSearchPath, Control * control);
	virtual ~MainWindow();

public:
	void show();

	void setRecentMenu(GtkWidget * submenu);
	void toolbarSelected(ToolbarData * d);
	ToolbarData * getSelectedToolbar();

	void updatePageNumbers(int page, int pagecount, int pdfpage);
	int getCurrentLayer();

	void setFontButtonFont(XojFont & font);
	XojFont getFontButtonFont();

	void setMaximized(bool maximized);
	bool isMaximized();

	XournalView * getXournal();

	void setSidebarVisible(bool visible);

	Control * getControl();

	void updateScrollbarSidebarPosition();

	void setUndoDescription(String description);
	void setRedoDescription(String description);

	void updateLayerCombobox();

	GtkWidget * getSpinPageNo();
	ToolbarModel * getToolbarModel();
	ToolMenuHandler * getToolMenuHandler();

	void setControlTmpDisabled(bool disabled);

	void updateToolbarMenu();

	void startToolbarEditMode();
	void endToolbarEditMode();

	GtkWidget ** getToolbarWidgets(int & length);
	String getToolbarName(GtkToolbar * toolbar);

private:
	void initToolbarAndMenu();

	static void pageNrSpinChangedCallback(GtkSpinButton * spinbutton, MainWindow * win);
	static void buttonCloseSidebarClicked(GtkButton * button, MainWindow * win);

	/**
	 * Sidebar show / hidden
	 */
	static void viewShowSidebar(GtkCheckMenuItem * checkmenuitem, MainWindow * control);

	/**
	 * Window close Button is pressed
	 */
	static bool deleteEventCallback(GtkWidget * widget, GdkEvent * event, Control * control);

	/**
	 * Callback fro window states, we ned to know if the window is fullscreen
	 */
	static bool windowStateEventCallback(GtkWidget * window, GdkEventWindowState * event, MainWindow * win);

	/**
	 * Callback for drag & drop files
	 */
	static void dragDataRecived(GtkWidget * widget, GdkDragContext * dragContext, gint x, gint y, GtkSelectionData * data, guint info, guint time, MainWindow * win);

private:
	XOJ_TYPE_ATTRIB;

	Control * control;

	XournalView * xournal;

	// Toolbars
	ToolMenuHandler * toolbar;
	GSList * toolbarGroup;
	GList * toolbarMenuData;
	ToolbarData * selectedToolbar;
	bool toolbarIntialized;

	GList * toolbarSpacerItems;

	GList * toolbarMenuitems;

	GtkWidget * scrollVertical;
	GtkWidget * scrollHorizontal;

	bool maximized;

	GtkWidget ** toolbarWidgets;
};

#endif /* __MAINWINDOW_H__ */
