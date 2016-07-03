package gui.popupAddWindow;

import javafx.scene.control.Button;
import javafx.scene.control.Control;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.control.ContentDisplay;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class AddSearchBox extends Region{
	
    private TextField textBox;
    private Button clearButton;
    
    private static final Image ICON_48 =new Image(AddSearchBox.class.getResourceAsStream("search-clear.png"));
    ImageView imageView = new ImageView(ICON_48);

    
    
	public AddSearchBox() {
		// suche über IMDB Datenbank
		// falls gefunden können die Daten über die Datenbank automatisch
		// ausgefüllt werden
		
		
        setMinHeight(24);
        setPrefSize(200, 24);
        setMaxSize(Control.USE_PREF_SIZE, Control.USE_PREF_SIZE);
        
		textBox = new TextField();
		textBox.setPromptText("Suche");
		
        clearButton = new Button();
        clearButton.setGraphic(imageView);
        
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
	
    protected void layoutChildren() {
        textBox.resize(getWidth(), getHeight());
        clearButton.resizeRelocate(getWidth() - 18, 12, 0, 0);
    }

}
