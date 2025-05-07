/*
Installing GTK:
sudo apt update
sudo apt install libgtk-4-dev

then pkg-config --cflags gtk4 to check configuration

compile:
gcc `pkg-config --cflags gtk4` main.c -o gtk_app `pkg-config --libs gtk4`
run:
./gtk_app
*/

#include <gtk/gtk.h>

// callback in response to an events (button clicks).

// handles button clicks
static void on_topic_clicked(GtkWidget *widget, gpointer user_data) {
    const char *topic = (const char *)user_data;
    g_print("Clicked: %s\n", topic);
}

// handles "Go Back" button clicks
static void on_go_back_clicked(GtkWidget *widget, gpointer user_data) {
    const gchar *page_name = (const gchar *)g_object_get_data(G_OBJECT(widget), "page_name");
    gtk_stack_set_visible_child_name(GTK_STACK(user_data), page_name);
}

// switching pages on button click
static void switch_page(GtkWidget *widget, gpointer user_data) {
    GtkStack *stack = GTK_STACK(user_data);
    const gchar *page_name = (const gchar *)g_object_get_data(G_OBJECT(widget), "page_name");

    if (!page_name) {
        g_print("Error: Page name is NULL.\n");
        return;
    }

    g_print("Switching to page: %s\n", page_name);
    gtk_stack_set_visible_child_name(stack, page_name);
}

// UI helper functions

// creates the "Go Back" button
static GtkWidget* create_go_back_button(GtkWidget *stack, const gchar *previous_page) {
    GtkWidget *btn_back = gtk_button_new_with_label("Go Back");
    g_object_set_data(G_OBJECT(btn_back), "page_name", (gpointer)previous_page);
    g_signal_connect(btn_back, "clicked", G_CALLBACK(on_go_back_clicked), stack);
    return btn_back;
}

// page constructors

// Beginner Tutorial page
static GtkWidget* create_beginner_tutorial_page(GtkWidget *stack) {
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_append(GTK_BOX(page), gtk_image_new_from_file("FullLogo.png"));
    gtk_box_append(GTK_BOX(page), gtk_label_new("Beginner Tutorials: Learn the Basics!"));

    const char *topics[] = {
        "Origins of Hedge Funds",
        "How They Work",
        "Basic Structure"
    };

    for (int i = 0; i < 3; i++) {
        GtkWidget *btn = gtk_button_new_with_label(topics[i]);
        g_signal_connect(btn, "clicked", G_CALLBACK(on_topic_clicked), (gpointer)topics[i]);
        gtk_box_append(GTK_BOX(page), btn);
    }

    gtk_box_append(GTK_BOX(page), create_go_back_button(stack, "activities"));
    return page;
}

// Advanced Tutorial page
static GtkWidget* create_advanced_tutorial_page(GtkWidget *stack) {
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_append(GTK_BOX(page), gtk_image_new_from_file("FullLogo.png"));
    gtk_box_append(GTK_BOX(page), gtk_label_new("Advanced Tutorials: Master Hedge Fund Strategies!"));

    const char *topics[] = {
        "Digital Assets and Tokenization",
        "Managing Risk",
        "Leveraging AI",
        "Current Market Conditions",
        "Strategies"
    };

    for (int i = 0; i < 5; i++) {
        GtkWidget *btn = gtk_button_new_with_label(topics[i]);
        g_signal_connect(btn, "clicked", G_CALLBACK(on_topic_clicked), (gpointer)topics[i]);
        gtk_box_append(GTK_BOX(page), btn);
    }

    gtk_box_append(GTK_BOX(page), create_go_back_button(stack, "activities"));
    return page;
}

// Login page
static GtkWidget* create_login_page(GtkWidget *stack) {
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_append(GTK_BOX(page), gtk_image_new_from_file("FullLogo.jpg"));
    gtk_box_append(GTK_BOX(page), gtk_label_new("Login"));

    GtkWidget *entry_username = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_username), "Username");

    GtkWidget *entry_password = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_password), "Password");
    gtk_entry_set_visibility(GTK_ENTRY(entry_password), FALSE);

    GtkWidget *btn_submit = gtk_button_new_with_label("Submit");
    g_object_set_data(G_OBJECT(btn_submit), "page_name", "activities");
    g_signal_connect(btn_submit, "clicked", G_CALLBACK(switch_page), stack);

    gtk_box_append(GTK_BOX(page), entry_username);
    gtk_box_append(GTK_BOX(page), entry_password);
    gtk_box_append(GTK_BOX(page), btn_submit);
    gtk_box_append(GTK_BOX(page), create_go_back_button(stack, "home"));

    return page;
}

// Create Account page
static GtkWidget* create_account_page(GtkWidget *stack) {
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_append(GTK_BOX(page), gtk_image_new_from_file("FullLogo.png"));
    gtk_box_append(GTK_BOX(page), gtk_label_new("Create Your Account"));

    const char *fields[] = {
        "Full Name", "Email Address", "Social Media (Optional)",
        "Occupation", "Experience / Skill Level",
        "Choose a Username", "Password"
    };

    for (int i = 0; i < 7; i++) {
        GtkWidget *entry = gtk_entry_new();
        gtk_entry_set_placeholder_text(GTK_ENTRY(entry), fields[i]);
        if (i == 6)
            gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE);
        gtk_box_append(GTK_BOX(page), entry);
    }

    GtkWidget *btn_submit = gtk_button_new_with_label("Submit");
    g_object_set_data(G_OBJECT(btn_submit), "page_name", "activities");
    g_signal_connect(btn_submit, "clicked", G_CALLBACK(switch_page), stack);
    gtk_box_append(GTK_BOX(page), btn_submit);
    gtk_box_append(GTK_BOX(page), create_go_back_button(stack, "home"));

    return page;
}

// Activities page
static GtkWidget* create_activities_page(GtkWidget *stack) {
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_append(GTK_BOX(page), gtk_image_new_from_file("FullLogo.png"));
    gtk_box_append(GTK_BOX(page), gtk_label_new("Select an Activity:"));

    GtkWidget *btn_beginner = gtk_button_new_with_label("Beginner Tutorials");
    GtkWidget *btn_advanced = gtk_button_new_with_label("Advanced Tutorials");

    g_object_set_data(G_OBJECT(btn_beginner), "page_name", "beginner_tutorial");
    g_object_set_data(G_OBJECT(btn_advanced), "page_name", "advanced_tutorial");

    g_signal_connect(btn_beginner, "clicked", G_CALLBACK(switch_page), stack);
    g_signal_connect(btn_advanced, "clicked", G_CALLBACK(switch_page), stack);

    gtk_box_append(GTK_BOX(page), btn_beginner);
    gtk_box_append(GTK_BOX(page), btn_advanced);
    gtk_box_append(GTK_BOX(page), create_go_back_button(stack, "home"));

    return page;
}

// main app called on activation

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hedge Funds For Dummies");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_window_set_child(GTK_WINDOW(window), vbox);

    GtkWidget *stack = gtk_stack_new();
    gtk_box_append(GTK_BOX(vbox), stack);

    // Home Page
    GtkWidget *home = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_append(GTK_BOX(home), gtk_image_new_from_file("FullLogo.png"));
    gtk_box_append(GTK_BOX(home), gtk_label_new("Welcome to Hedge Funds For Dummies!"));
    gtk_box_append(GTK_BOX(home), gtk_label_new("Login or create an account to begin."));

    GtkWidget *btn_create = gtk_button_new_with_label("Create Account");
    GtkWidget *btn_login = gtk_button_new_with_label("Login");

    g_object_set_data(G_OBJECT(btn_create), "page_name", "create_account");
    g_object_set_data(G_OBJECT(btn_login), "page_name", "login");

    g_signal_connect(btn_create, "clicked", G_CALLBACK(switch_page), stack);
    g_signal_connect(btn_login, "clicked", G_CALLBACK(switch_page), stack);

    gtk_box_append(GTK_BOX(home), btn_create);
    gtk_box_append(GTK_BOX(home), btn_login);

    // Add pages to the stack
    gtk_stack_add_named(GTK_STACK(stack), home, "home");
    gtk_stack_add_named(GTK_STACK(stack), create_login_page(stack), "login");
    gtk_stack_add_named(GTK_STACK(stack), create_account_page(stack), "create_account");
    gtk_stack_add_named(GTK_STACK(stack), create_activities_page(stack), "activities");
    gtk_stack_add_named(GTK_STACK(stack), create_beginner_tutorial_page(stack), "beginner_tutorial");
    gtk_stack_add_named(GTK_STACK(stack), create_advanced_tutorial_page(stack), "advanced_tutorial");

    gtk_stack_set_visible_child_name(GTK_STACK(stack), "home");
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("com.osu.HedgeFundsForDummies", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
/*

// basic stack Outlinemanage multiple pages
GtkWidget *stack = gtk_stack_new();
gtk_box_append(GTK_BOX(vbox), stack); // Add to main layout

// creating the pages
GtkWidget *home_page = gtk_label_new("Hedge Funds For Dummies");
GtkWidget *create_your_account = gtk_label_new("Create Your Account");
GtkWidget *login_page = gtk_label_new("Login");
GtkWidget *login_assistance = gtk_label_new("login Assistance");
GtkWidget *activities = gtk_label_new("Activities");
GtkWidget *basic_tutorial = gtk_label_new("Basic Tutorial");
GtkWidget *advanced_tutorial = gtk_label_new("Advanced Tutorial");
GtkWidget *simulation = gtk_label_new("Simulator");
GtkWidget *results = gtk_label_new("Results");

// add pages to the stack 
gtk_stack_add_named(GTK_STACK(stack), home_page, "Hedge Funds For Dummies");
gtk_stack_add_named(GTK_STACK(stack), create_your_account, "Create Your Account");
gtk_stack_add_named(GTK_STACK(stack), login_page, "Login");
gtk_stack_add_named(GTK_STACK(stack), login_assistance, "login Assistance");
gtk_stack_add_named(GTK_STACK(stack), basic_tutorial, "Basic Tutorial");
gtk_stack_add_named(GTK_STACK(stack), advanced_tutorial, "Advanced Tutorial");
gtk_stack_add_named(GTK_STACK(stack), simulation, "Simulator");
gtk_stack_add_named(GTK_STACK(stack), results, "Results");

// set the initial page to be displayed
gtk_stack_set_visible_child_name(GTK_STACK(stack), "Hedge Funds For Dummies");


*/