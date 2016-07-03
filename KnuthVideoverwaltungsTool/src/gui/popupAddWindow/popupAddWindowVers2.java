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
public class popupAddWindowVers2 {

	public popupAddWindowVers2(Stage primaryStage) {
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

		HBox checkBoxesGenre = addCheckBoxesGenre();

		HBox languageBox = addCheckTreeViewLanguage();
		// HBox languageBox = addCheck();
		languageBox.setPadding(new Insets(15, 12, 15, 12));
		languageBox.setSpacing(10); // Gap between nodes
		languageBox.setStyle("-fx-background-color: #666666;");

		// HBox imdbSearchPanel = new HBox();
		// imdbSearchPanel.setPadding(new Insets(15, 12, 15, 12));
		// imdbSearchPanel.setSpacing(10); // Gap between nodes
		// imdbSearchPanel.setStyle("-fx-background-color: #666666;");
		//
		//
		//
		//
		// imdbSearchPanel.getChildren().addAll(new AddSearchBox(),
		// addIMDBSerachButton());
		// VBox vboxAll = new VBox(10);

		// vboxAll.getChildren().addAll(checkBoxesGenre, imdbSearchPanel,
		// languageBox);
		// rootGroup.getChildren().addAll(vboxAll);
		rootGroup.getChildren().addAll(allScenes);
		popupAdd.show();
	}

	private HBox topHBoxScene() {
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(15, 12, 15, 12));
		hbox.setSpacing(10); // Gap between nodes
		hbox.setStyle("-fx-background-color: #666666;");

		hbox.getChildren().addAll(new AddSearchBox(), addIMDBSerachButton());

		return hbox;
	}

	private HBox leftHBoxScene() {
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(15, 12, 15, 12));
		hbox.setSpacing(10); // Gap between nodes
		hbox.setStyle("-fx-background-color: #336699;");

		return hbox;
	}

	private HBox rightHBoxScene() {
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(15, 12, 15, 12));
		hbox.setSpacing(10); // Gap between nodes
		hbox.setStyle("-fx-background-color: #336699;");

		// HBox languageBox = addCheckTreeViewLanguage();
		// HBox languageBox = addCheck();

		hbox.getChildren().addAll(getLanguageCheckComboBox());
		return hbox;
	}

	private HBox addCheckBoxesGenre() {
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(15, 12, 15, 12));
		hbox.setSpacing(10); // Gap between nodes
		hbox.setStyle("-fx-background-color: #336699;");

		// add some node to scene

		Text text = new Text(20, 110, "JavaFX");

		Button btnAddTitle = new Button("Titel Hinzufügen");
		// add text to the main root group

		hbox.getChildren().addAll(text, btnAddTitle);
		return hbox;
	}

	private void addCheckBoxesLanguage() {

	}

	private void addCheckBoxesSubTitle() {

	}

	private void addRadioButtonCatagories() {

	}

	private void addTextAreaComment() {
	}

	private void addComboBox(ObservableList strings) {

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

	private HBox addIMDBSerachButton() {
		HBox hbox = new HBox();
		Image ICON_IMDB = new Image(popupAddWindowVers2.class.getResourceAsStream("imdb_small.png"));
		ImageView imageViewIMDB = new ImageView(ICON_IMDB);

		Button btnAddFromIMDB = new Button("Add from IMDB Database", imageViewIMDB);

		hbox.getChildren().addAll(btnAddFromIMDB);
		return hbox;

	}

}
