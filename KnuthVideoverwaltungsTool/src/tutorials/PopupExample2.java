package tutorials;


import javafx.application.Application; 
import javafx.event.ActionEvent; 
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene; 
import javafx.scene.control.Button; 
import javafx.scene.layout.HBox; 
import javafx.scene.paint.Color; 
import javafx.scene.shape.Circle;
import javafx.scene.text.Text;
import javafx.stage.Popup; 
import javafx.stage.Stage; 

public class PopupExample2 extends Application { 
   public static void main(String[] args) { 
       launch(args); 
   } 

   @Override 
   public void start(final Stage primaryStage) { 
       primaryStage.setTitle("Popup Example"); 
       final Popup popup = createPopup(); 

       final HBox layout = new HBox(10); 
       Button show = new Button("Show"); 
       show.setOnAction(new EventHandler<ActionEvent>() { 
           @Override 
           public void handle(ActionEvent event) { 
               popup.show(layout, 0,0); 
           } 
       }); 

       Button hide = new Button("Hide"); 
       hide.setOnAction(new EventHandler<ActionEvent>() { 
           @Override 
           public void handle(ActionEvent event) { 
               popup.hide(); 
           } 
       }); 


       layout.setStyle("-fx-background-color: cornsilk; -fx-padding: 10;"); 
       layout.getChildren().addAll(show, hide); 
       primaryStage.setScene(new Scene(layout)); 
       primaryStage.show(); 
   } 

   private Popup createPopup() { 
       final Popup popup = new Popup(); 
	Group rootGroup = new Group();

       popup.setAutoHide(true); 
       popup.setX(300); 
       popup.setY(200); 
       Text text = new Text(20, 110, "JavaFX");
       popup.getContent().addAll(new Circle(95, 45, 190, Color.AQUAMARINE), text); 

       return popup; 
   } 
}