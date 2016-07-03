package gui.popupAddWindow;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ListChangeListener;
import javafx.collections.ObservableList;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBoxTreeItem;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.TreeItem;
import javafx.scene.effect.Lighting;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.control.TreeView;

import org.controlsfx.control.CheckComboBox;
import org.controlsfx.control.CheckTreeView;

/**
 * A sample with a control that creates a decorated stage that is centered on
 * your desktop.
 *
 * @see javafx.stage.Stage
 * @see javafx.scene.Scene
 */
public class popupAddWindowVers3 {

	public popupAddWindowVers3(Stage primaryStage) {
		final Stage popupAdd = new Stage();
		// create root node of scene, i.e. group
		Group rootGroup = new Group();
		// create scene with set width, height
		Scene scene = new Scene(rootGroup, 600, 600);
		// set scene to stage
		popupAdd.setScene(scene);
		// center stage on screen
		popupAdd.centerOnScreen();
		// show the stage
		final BorderPane allScenes = new BorderPane();

		allScenes.setTop(topHBoxScene());
		allScenes.setLeft(leftHBoxScene());
		allScenes.setRight(rightHBoxScene());

		rootGroup.getChildren().addAll(allScenes);
		popupAdd.show();
	}

	private HBox topHBoxScene() {
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(15, 12, 15, 12));
		hbox.setSpacing(10); // Gap between nodes
		hbox.setStyle("-fx-background-color: #666666;");

		hbox.getChildren().addAll(new AddSearchBox(), getIMDBSerachButton());

		return hbox;
	}

	private VBox leftHBoxScene() {
		VBox vbox = new VBox();
		vbox.setPadding(new Insets(15, 12, 15, 12));
		vbox.setSpacing(10); // Gap between nodes
		vbox.setStyle("-fx-background-color: #336699;");

		return vbox;
	}

	private VBox rightHBoxScene() {
		VBox vbox = new VBox();
		vbox.setPadding(new Insets(15, 12, 15, 12));
		vbox.setSpacing(10); // Gap between nodes
		vbox.setStyle("-fx-background-color: #336699;");

		// HBox languageBox = addCheckTreeViewLanguage();
		// HBox languageBox = addCheck();

		vbox.getChildren().add(getCategories()); 
		vbox.getChildren().add(getLanguageCheckComboBox());
		return vbox;
	}

	private VBox addCheckBoxesGenre() {
		VBox vbox = new VBox();
		vbox.setPadding(new Insets(15, 12, 15, 12));
		vbox.setSpacing(10); // Gap between nodes
		vbox.setStyle("-fx-background-color: #336699;");

		// add some node to scene

		Text text = new Text(20, 110, "JavaFX");

		Button btnAddTitle = new Button("Titel Hinzufügen");
		// add text to the main root group

		vbox.getChildren().addAll(text, btnAddTitle);
		return vbox;
	}


	private VBox getCategories() {
		VBox vbox = new VBox();
		HBox hbox = new HBox();
	
		hbox.setSpacing(5); // Gap between nodes
		vbox.setPadding(new Insets(15, 12, 15, 12));
		vbox.setSpacing(5); // Gap between nodes
		vbox.setStyle("-fx-background-color: #336699;");
		
		Label label = new Label("Kategorie");

		Label lFilme = new Label("Filme");

		Label lSerien = new Label("Serien");
		
		String str = "Filme";
		RadioButton rb1 = new RadioButton(str);
		RadioButton rb2 = new RadioButton("Serien");
		rb1.setStyle("-fx-font: 25px 'Tahoma'; text=Hello World!!");
		rb2.setStyle("-fx-font-size: 14px");

		


		hbox.getChildren().addAll(rb1, rb2);
		vbox.getChildren().addAll(label, hbox);

		return vbox;
	}


	private HBox addCheckTreeViewLanguage() {
		HBox hbox = new HBox();

		// create the data to show in the CheckTreeView
		CheckBoxTreeItem<String> languageSelections = new CheckBoxTreeItem<String>("Sprachen");
		languageSelections.setExpanded(true);
		languageSelections.getChildren().addAll(new CheckBoxTreeItem<String>("Englisch"),
				new CheckBoxTreeItem<String>("Französisch"), new CheckBoxTreeItem<String>("Deutsch"),
				new CheckBoxTreeItem<String>("Spanisch"), new CheckBoxTreeItem<String>("Türkisch"),
				new CheckBoxTreeItem<String>("Arabisch"), new CheckBoxTreeItem<String>("Russisch"),
				new CheckBoxTreeItem<String>("Portugiesisch"), new CheckBoxTreeItem<String>("Japanisch"),
				new CheckBoxTreeItem<String>("Koreanisch"));

		// Create the CheckTreeView with the data
		final CheckTreeView<String> checkTreeView = new CheckTreeView<>(languageSelections);

		// and listen to the relevant events (e.g. when the checked items
		// change).
		checkTreeView.getCheckModel().getCheckedItems().addListener(new ListChangeListener<TreeItem<String>>() {
			public void onChanged(ListChangeListener.Change<? extends TreeItem<String>> c) {
				System.out.println(checkTreeView.getCheckModel().getCheckedItems());
			}
		});

		hbox.getChildren().add(checkTreeView);
		return hbox;
	}

	private HBox getLanguageCheckComboBox() {
		HBox hbox = new HBox();

		final ObservableList<String> strings = FXCollections.observableArrayList();

		strings.addAll("Englisch", "Französisch", "Deutsch", "Spanisch", "Türkisch", "Arabisch", "Russisch",
				"Portugiesisch", "Japanisch", "Koreanisch");

		// create the data to show
		CheckComboBox<String> checkComboBox = new CheckComboBox<String>(strings);

		// and listen to the relevant events (e.g. when the checked items
		// change).
		checkComboBox.getCheckModel().getCheckedItems().addListener(new ListChangeListener<String>() {
			public void onChanged(ListChangeListener.Change<? extends String> c) {
				System.out.println(checkComboBox.getCheckModel().getCheckedItems());
			}
		});

		hbox.getChildren().add(checkComboBox);
		return hbox;

	}

	private HBox getIMDBSerachButton() {
		HBox hbox = new HBox();
		Image ICON_IMDB = new Image(popupAddWindowVers3.class.getResourceAsStream("imdb_small.png"));
		ImageView imageViewIMDB = new ImageView(ICON_IMDB);
		// mit Icon
//		Button btnAddFromIMDB = new Button("Add from IMDB Database", imageViewIMDB);
		// ohne Icon
		Button btnAddFromIMDB = new Button("Add from IMDB Database");

		hbox.getChildren().addAll(btnAddFromIMDB);
		return hbox;

	}

}
