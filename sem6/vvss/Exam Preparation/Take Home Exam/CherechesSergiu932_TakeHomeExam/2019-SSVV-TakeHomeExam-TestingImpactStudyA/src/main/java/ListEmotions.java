import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.*;

public class ListEmotions {

    private List<Emotion> lstEmotions;

    public ListEmotions(List<Emotion> newLstEmotions){
        this.lstEmotions = newLstEmotions;
    }

    public int getNumberOfEmotions(){
        return lstEmotions.size();
    }

    // Task A_1
    // return the number of emotion of the given EmotionType et
    // Remark: No test cases are going to be created.
    public int howGivenManyEmotionTypeInListEmotions(EmotionType et){
        int nJE =0 ;

        for (Emotion e: lstEmotions) {
            if (e.getEmotionType().equals(et)){
                nJE += 1;
            }
        }

        return nJE;
    }

    // Task A_2
    // return the list of predominant emotions
    // Remark: Create a set of test cases to assess the correctness of your code.
    //         Create a class to test this method, several test cases are needed.
    //         One sample test case is provided in class Test_ListEmotions.
    public List<Emotion> predominantEmotion(){
        List<Emotion> lstEPredominant = new ArrayList<Emotion>();
        //Add code here

        Map<EmotionType, Integer> emotionMap = new HashMap<>();

        emotionMap.put(EmotionType.Joy, 0);
        emotionMap.put(EmotionType.Anger, 0);
        emotionMap.put(EmotionType.Sadness, 0);
        emotionMap.put(EmotionType.Disgust, 0);
        emotionMap.put(EmotionType.Fear, 0);

        for (Emotion emot: this.lstEmotions) {
            emotionMap.put(emot.getEmotionType(), emotionMap.get(emot.getEmotionType()) + 1);
        }

        int maX = 0;
        List<EmotionType> et = new ArrayList<>();

        for (Map. Entry<EmotionType, Integer> entry : emotionMap.entrySet()) {
            if(entry.getValue() > maX){
                maX = entry.getValue();
            }
        }

        if (maX == 0){
            maX = -1;
        }

        for (Map. Entry<EmotionType, Integer> entry : emotionMap.entrySet()) {
            if(entry.getValue() == maX){
                et.add(entry.getKey());
            }
        }

        for (Emotion emot: lstEmotions) {

            if (et.contains(emot.getEmotionType())){
                lstEPredominant.add(emot);
            }
        }
        
        return  lstEPredominant;
    }

    // Task A_3
    // Eliminate the emotions that are of given type EmotionType et
    // Remark: A set of test cases to assess the correctness of your code is provided.
    //         A class to test this method was created, several test cases were added.
    //         Use the test cases to check for your code.
    public void eliminateAllProvidedEmotion(EmotionType et){

        List<Emotion> em_lst = new ArrayList<>();

        for (Emotion emot : lstEmotions) {
            if (emot.getEmotionType() != et) { em_lst.add(emot); }
        }

        lstEmotions = em_lst;
    }
}
