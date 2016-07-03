package tutorials;

import java.util.Arrays;  
import java.util.List;  
  
import javafx.application.Application;  
import javafx.beans.value.ChangeListener;  
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;  
import javafx.scene.control.CheckMenuItem;
import javafx.scene.control.ComboBox;
import javafx.scene.control.ComboBoxBuilder;
import javafx.scene.control.ListView;  
import javafx.scene.control.MenuButton;  
import javafx.scene.layout.BorderPane;  
import javafx.stage.Stage;  
import org.controlsfx.control.CheckComboBox;
  
public class MultipleSelectionDropdownTest2 extends Application {  
	
  
    @Override  
    public void start(Stage primaryStage) {  
//        final MenuButton choices = new MenuButton("Fruit");  
//        final List<CheckMenuItem> checkItems = Arrays.asList(  
//            new CheckMenuItem("Apples"),   
//            new CheckMenuItem("Oranges"),   
//            new CheckMenuItem("Pears"),   
//            new CheckMenuItem("Grapes"),   
//            new CheckMenuItem("Mangoes")  
//        );  
//        choices.getItems().addAll(checkItems);  
        
                
        ObservableList<String> checkItems = FXCollections.observableArrayList(
                "Option 1", "Option 2", "Option 3",
                "Option 4", "Option 5", "Option 6",
                "Longer ComboBox item",
                "Option 7", "Option 8", "Option 9",
                "Option 10", "Option 12");
        
        CheckComboBox<String> choices = new CheckComboBox<String>(checkItems);

        
          // Keep track of selected items  
        final ListView<String> selectedItems = new ListView<>();  
        for (String item : checkItems) {  
            item.selectedProperty().addListener(new ChangeListener<Boolean>() {  
                @Override  
                public void changed(ObservableValue<? extends Boolean> obs,  
                        Boolean wasPreviouslySelected, Boolean isNowSelected) {  
                    if (isNowSelected) {  
                        selectedItems.getItems().add(item.getText());  
                    } else {  
                        selectedItems.getItems().remove(item.getText());  
                    }  
                }  
            });  
        }  
  
        BorderPane root = new BorderPane();  
        root.setTop(choices);  
        root.setCenter(selectedItems);  
        primaryStage.setScene(new Scene(root, 600, 400));  
        primaryStage.show();  
    }  
  
    public static void main(String[] args) {  
        launch(args);  
    }  
}  