package tutorials;

/**
 * Copyright (c) 2008, 2012 Oracle and/or its affiliates.
 * All rights reserved. Use is subject to license terms.
 */
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.Control;
import javafx.scene.control.TextField;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import javafx.scene.layout.VBoxBuilder;

/**
 * A sample that demonstrates use of CSS to create a search box.
 *
 * @see javafx.scene.control.TextField
 * @resource SearchBox.css
 * @resource search-box.png
 * @resource search-clear-over.png
 * @resource search-clear.png
 */
public class SearchBoxSample extends Application {

    private void init(Stage primaryStage) {
        Group root = new Group();
        primaryStage.setScene(new Scene(root));
        String searchBoxCss = SearchBoxSample.class.getResource("SearchBox.css").toExternalForm();
        @SuppressWarnings("deprecation")
		VBox vbox = VBoxBuilder.create().build();
        vbox.getStylesheets().add(searchBoxCss);
        vbox.setPrefWidth(200);
        vbox.setMaxWidth(Control.USE_PREF_SIZE);
        vbox.getChildren().add(new SearchBox());
        root.getChildren().add(vbox);
    }

    private static class SearchBox extends Region {

        private TextField textBox;
        private Button clearButton;

        public SearchBox() {
            setId("SearchBox");
            getStyleClass().add("search-box");
            setMinHeight(24);
            setPrefSize(200, 24);
            setMaxSize(Control.USE_PREF_SIZE, Control.USE_PREF_SIZE);
            textBox = new TextField();
            textBox.setPromptText("Search");
            clearButton = new Button();
            clearButton.setVisible(false);
            getChildren().addAll(textBox, clearButton);
            clearButton.setOnAction(new EventHandler<ActionEvent>() {                
                @Override public void handle(ActionEvent actionEvent) {
                    textBox.setText("");
                    textBox.requestFocus();
                }
            });
            textBox.textProperty().addListener(new ChangeListener<String>() {
                @Override public void changed(ObservableValue<? extends String> observable, String oldValue, String newValue) {
                    clearButton.setVisible(textBox.getText().length() != 0);
                }
            });
        }

        @Override
        protected void layoutChildren() {
            textBox.resize(getWidth(), getHeight());
            clearButton.resizeRelocate(getWidth() - 18, 6, 12, 13);
        }
    }

    @Override public void start(Stage primaryStage) throws Exception {
        init(primaryStage);
        primaryStage.show();
    }
    public static void main(String[] args) { launch(args); }
}
